#!/usr/bin/env python3

import sys
import os
import re
import argparse
from contextlib import contextmanager
import subprocess

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

def commit_file(filepath: str, message: str):
    subprocess.run(["git", "add", "--verbose", filepath], check=True)
    subprocess.run(["git", "commit", "--verbose", "-m", message], check=True)

@contextmanager
def update_file(filepath: str):
    if not os.access(filepath, os.R_OK):
        raise Exception("update_file: file not found: " + filepath)
    with open(filepath, "r") as input:
        with open(filepath + ".new", "w") as output:
            yield (input, output)
    # os.rename(filepath, filepath + ".bak")
    os.rename(filepath + ".new", filepath)
    print("Updated " + filepath)

def update_project_file(args, project_dir):
    fixproj_path = f"{project_dir}/fixproj.toml"
    with update_file(fixproj_path) as (input, output):
        input_lines = list(input)
        output_lines = input_lines
        version = ''
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
        output.write("".join(output_lines))
    if args.commit and version != '':
        commit_file(fixproj_path, 'version ' + version)

def parse_args():
    parser = argparse.ArgumentParser(
                    prog='verup')
    parser.add_argument('projects', nargs='*', help='target projects to change', default=['.'])
    parser.add_argument('--commit', action='store_true', help='commit', default=False)
    args = parser.parse_args()
    return args

if __name__ == "__main__":
    args = parse_args()

    for project_dir in args.projects:
        update_project_file(args, project_dir)
