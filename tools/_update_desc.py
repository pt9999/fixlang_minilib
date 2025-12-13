import re

# Updates descriptions of `registry.toml`.
# This script should be executed in the top directory.

descriptions = {}

with open("README.md", "r") as f:
    for line in f:
        m = re.match(r'^\|\[(minilib-.*)\]\(.*\)\|(.*)\|', line)
        if m:
            descriptions[m.group(1)] = '"Minilib: ' + m.group(2).strip() + '"'

name = ""
with open("registry.toml", "r") as input:
    with open("registry.toml.new", "w") as output:
        for line in input:
            m = re.match(r'^description =', line)
            if m:
                continue
            output.write(line)
            m = re.match(r'^name = "(.*)"', line)
            if m:
                name = m.group(1)
            m = re.match(r'^git =', line)
            if m:
                if name in descriptions:
                    output.write("description = " + descriptions[name] + "\n")
                else:
                    output.write("description = \"---\"\n")

