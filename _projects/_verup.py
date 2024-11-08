#!/usr/bin/env python3

import sys
import os
import re
import argparse

def increment_patch_version(version: str) -> str:
    major, minor, patch = version.split(".", 3)
    if not (
        re.match(r'\d+', major) and
        re.match(r'\d+', minor) and
        re.match(r'\d+', patch)
    ):
        raise "invalid version format"
    patch = str(int(patch) + 1)
    return f"{major}.{minor}.{patch}"

def update_fixproj_toml(args, project_dir, input_lines: list[str]) -> list[str]:
    output_lines = input_lines
    for i, line in enumerate(output_lines):
        if "=" not in line:
            continue
        key, value = line.split("=", 1)
        key = key.strip()
        value = value.strip()
        if key != "version":
            continue
        version = value.replace("\"", "")
        version = increment_patch_version(version)
        line = f"{key} = \"{version}\"\n"
        output_lines[i] = line
        break
    return output_lines

def update_project(args, project_dir):
    fixproj_path = f"{project_dir}/fixproj.toml"
    if not os.access(fixproj_path, os.R_OK):
        print("WARNING: file not found: " + fixproj_path)
        return
    with open(fixproj_path, "r") as f:
        input_lines = list(f)
    output_lines = update_fixproj_toml(args, project_dir, input_lines)
    with open(fixproj_path + ".new", "w") as f:
        f.write("".join(output_lines))
    os.rename(fixproj_path, fixproj_path + ".bak")
    os.rename(fixproj_path + ".new", fixproj_path)
    print("Updated " + fixproj_path)

def parse_args():
    parser = argparse.ArgumentParser(
                    prog='verup')
    parser.add_argument('projects', nargs='*', help='target projects to change', default=['fixlang-minilib-common'])
    args = parser.parse_args()
    return args
    

if __name__ == "__main__":
    args = parse_args()

    for project_dir in args.projects:
        update_project(args, project_dir)
