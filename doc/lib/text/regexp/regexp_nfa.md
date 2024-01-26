# regexp_nfa.fix

## module Minilib.Text.RegExp.RegExpNFA

NFA (Nondeterministic Finite Automaton). This is internal module of `RegExp`.

For details, see web pages below.
- https://swtch.com/~rsc/regexp/regexp1.html
- https://zenn.dev/canalun/articles/regexp_and_automaton


### type Group

Type of a matched group.
The group is represented as two stream positions: `(begin, end)`.
`-1` means that the stream position is undefined.

```
type Group = (I64, I64);
```
### type Groups

Type of the array of matched groups.

```
type Groups = Array Group;
```
### type QuantID

Type of special quantifiers ID.
Special quantifiers are quantifieres other than `X?` `X*` `X+`.
In other words, they are `X{n}` `X{n,}` `X{n,m}` etc.
Special quantifiers are hard to implement only using node transition,
so its iteration count are stored in the NFA state, and managed by `sa_quant_*` actions.

```
type QuantID = I64;
```
### type NFA

NFA

```
type NFA = unbox struct {
    nodes: Array NFANode,     // array of nodes
    initial_node: NodeID,     // initial node
    accepting_node: NodeID,   // accepting node
    group_count: I64,         // group count
    quant_count: I64,         // special quant count
    debug: Bool               // true if debug
};
```
### namespace NFA

#### empty: NFA;

An empty NFA.

#### new_node: NFA -> (NFA, NodeID);

Creates new node. Returns the new node id.

#### get_node: NodeID -> NFA -> NFANode;

`nfa.get_node(id)` gets the node whose @id is `id`.

#### mod_node: NodeID -> (NFANode -> NFANode) -> NFA -> NFA;

`nfa.mod_node(id, f)` modifies the node whose @id is `id`.

#### set_frag_output: NFAFrag -> NodeID -> NFA -> NFA;

`nfa.set_frag_output(frag, out)` sets the output of the fragment to `out`.

#### new_quant: NFA -> (NFA, QuantID);

Creates new quant. Returns the new quant id.

#### compile: Pattern -> NFA;

`NFA::compile(pattern)` compiles a pattern to NFA.

#### execute: String -> NFA -> NFAExecutor;

`nfa.execute(target)` executes matching.

#### debug: String -> NFA -> ();

#### `impl NFA: ToString`

### type NFANodeAction

Actions that has to be performed before the state makes a transition to `node.@out_on_action`.

```
type NFANodeAction = unbox union {
    sa_none: (),
    sa_char_match: CharClass,               // The input character must match to the character class
    sa_assert: PAssertion,                  // The assertion to be checked
    sa_group_begin: I64,                    // The beginning of a group
    sa_group_end: I64,                      // The end of a group
    sa_quant_begin: QuantID,                // The beginning of a special quantifier
    sa_quant_loop: QuantID,                 // The loop of a special quantifier
    sa_quant_end: (QuantID, I64, I64)       // The end of a special quantifier
};
```
#### `impl NFANodeAction: ToString`

### type NFANode

NFA node

NFA node has one input (ID of this node) and three outputs
(one output guarded by the action, and two outputs with no guard).

```
type NFANode = unbox struct {
    id: NodeID,                // ID of this node
    action: NFANodeAction,     // action
    output_on_action: NodeID,  // next node when the action succeeded
    output: NodeID,            // next node with empty string
    output2: NodeID,           // next node with empty string part 2
    label: String              // a label to display
};
```
### type NodeID

ID of NFA node. -1 is invalid value.

```
type NodeID = unbox struct {
    val: I64
};
```
#### `impl NodeID: ToString`

#### `impl NodeID: Eq`

#### `impl NodeID: Hash`

### namespace NFANode

#### empty: NFANode;

An empty node

#### `impl NFANode: ToString`

### type NFAFrag

NFA Fragment

NFA Fragment is a collection of nodes. It exports one input,
And a function to set the output.
Internally, the output of a fragment is a collection of outputs of one or more nodes.
Calling `set_output()` will change them all.

```
type NFAFrag = unbox struct {
    input: NodeID,                     // NodeID of input of this fragment
    set_output: NodeID -> NFA -> NFA,  // A function to set NodeID of output
                                       // of this fragment
    label: String                      // A label to display (for debugging only)
};
```
### namespace NFAFrag

#### compile_pattern: Pattern -> NFA -> (NFA, NFAFrag);

`nfa.compile_pattern(pattern)` compiles a pattern to a fragment.

### type NFAState

NFA state

```
type NFAState = unbox struct {
    id: NodeID,         // NodeID where this state currently stays
    groups: Groups,     // Captured groups
    quants: Array I64   // Special quantifier counters
};
```
#### `impl NFAState: Eq`

#### `impl NFAState: Hash`

#### `impl NFAState: ToString`

### namespace NFAState

#### make: NodeID -> Groups -> NFAState;

Creates a NFA state.

#### transition: NodeID -> NFAState -> NFAState;

Makes transition to next node.

#### get_group: I64 ->  NFAState -> Group;

Gets specified group. If group index is out of range, returns (-1, -1).

#### mod_group: I64 -> (Group -> Group) -> NFAState -> NFAState;

Modify specified group.

#### get_quant: QuantID -> NFAState -> I64;

get quant loop count

#### set_quant: QuantID -> I64 -> NFAState -> NFAState;

set quant loop count

#### overlaps: NFAState -> NFAState -> Bool;

#### group_length: I64 -> NFAState -> I64;

Gets the length of specified group.

#### collect_first_match: Array NFAState -> Option NFAState;

Collects first match.

#### collect_all_non_overlapping: Array NFAState -> Array NFAState;

Collects all non overlapping matches.

### type NFAStateSet

NFA state set, used for NFA state transition

```
type NFAStateSet = unbox struct {
    array: Array NFAState,              // array of states
    map: HashMap NFAState Bool          // a hashmap to check whether the state is contained or not
};
```
### namespace NFAStateSet

#### empty: I64 -> NFAStateSet;

`NFAStateSet::empty(node_count)` creates an empty state set.
`node_count` is number of NFA nodes.

#### is_empty: NFAStateSet -> Bool;

Checks whether the state set is empty.

#### contains: NFAState -> NFAStateSet -> Bool;

Checks whether the state set contains a state.

#### add: NFAState -> NFAStateSet -> NFAStateSet;

Adds a state to the state set.

#### to_iter: NFAStateSet -> Iterator NFAState;

Returns an iterator of the states.

### type NFAExecutor

The NFA executor

```
type NFAExecutor = unbox struct {
    stream: Stream,                     // stream of characters
    nfa: NFA,                           // NFA
    empty_state_set: NFAStateSet,       // an empty state set
    state_set: NFAStateSet,             // current state set
    stack: Iterator NFAState,           // temporary stack for transition
    accepted_states: NFAStateSet        // accepted states
};
```
### namespace NFAExecutor

#### make: Stream -> NFA -> NFAExecutor;

Creates an executor.

#### execute: NFAExecutor -> NFAExecutor;

Make transitions until end of stream is reached, or the state set becomes empty.

### type ReplaceFrag

A replacement fragment

```
type ReplaceFrag = unbox union {
    rep_literal: U8,
    rep_group: I64
};
```
### namespace Replacement

#### compile: String -> Array ReplaceFrag;

Compiles a replacement string to fragments.

#### calc_replacement: String -> Array ReplaceFrag -> NFAState -> String;

Calculates actual replacement string.

