all:

test: test-retained-ptr test-typename test-typed-ptr

test-retained-ptr:
	fix run -f retained_ptr.fix -f retained_ptr_example.fix

test-typename:
	fix run -f typename.fix -f typename_example.fix

test-typed-ptr:
	fix run -f typed_ptr.fix -f typed_ptr_example.fix -f retained_ptr.fix -f typename.fix
