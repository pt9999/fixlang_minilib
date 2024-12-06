#!/usr/bin/env python3

import sys
import os
import re
import argparse
from contextlib import contextmanager
from collections import namedtuple
import subprocess


def or_empty(s: str | None) -> str:
    return "" if s is None else s


def increment_prerelease(prerelease: str) -> str:
    match = re.match(r"^(.*\D)?(\d+)?$", prerelease)
    if not match:
        raise Exception(f"invalid prerelease format: {prerelease}")
    prefix = or_empty(match.group(1))
    suffix = or_empty(match.group(2))
    if suffix == "":
        suffix = "2"
    else:
        suffix = str(int(suffix) + 1)
    return f"{prefix}{suffix}"


def increment_version(version: str) -> str:
    match = re.match(r"^(\d+.\d+.\d+)(-[-0-9A-Za-z]+)?(\+[-0-9A-Za-z]+)?$", version)
    if not match:
        raise Exception(f"invalid version format: {version}")
    triplets = match.group(1)
    prerelease = or_empty(match.group(2))
    metadata = or_empty(match.group(3))
    major, minor, patch = triplets.split(".", 3)
    if prerelease == "":
        patch = str(int(patch) + 1)
    else:
        prerelease = increment_prerelease(prerelease)
    return f"{major}.{minor}.{patch}{prerelease}{metadata}"


class GitHelper(object):
    def __init__(self):
        pass

    def run_subprocess(self, cmd_args):
        print("+ " + " ".join(cmd_args))
        subprocess.run(cmd_args, check=True)

    def commit_file(self, args, filepath: str, version: str):
        self.run_subprocess(["git", "add", "--verbose", filepath])
        message = "version " + version
        self.run_subprocess(["git", "commit", "--verbose", "-m", message])
        if args.tag:
            self.run_subprocess(["git", "tag", version])
        if args.push:
            self.run_subprocess(["git", "push"])
        if args.push and args.tag:
            self.run_subprocess(["git", "push", "origin", version])


# ---------------------------------------------------
# Project file editing
# ---------------------------------------------------

Field = namedtuple("Field", ["key", "value", "line_index"])


class ProjectFile(object):
    def __init__(self, filepath: str) -> None:
        self.filepath = filepath
        with open(self.filepath, "r") as input:
            self.lines = list(input)

    def save(self) -> None:
        with open(self.filepath, "w") as output:
            output.write("".join(self.lines))
            print("Wrote " + self.filepath)

    def find_field(self, section_to_find: str, key_to_find: str) -> Field:
        section = ""
        for line_index, line in enumerate(self.lines):
            line = line.strip()
            match = re.match(r"^\[(.*)\]$", line)
            if match:
                section = match.group(1)
                continue
            if "=" not in line:
                continue
            key, value = line.split("=", 1)
            key = key.strip()
            value = value.strip()
            if section == section_to_find and key == key_to_find:
                return Field(key, value, line_index)
        raise Exception("field not found: {section_to_find}.{key_to_find}")

    def get_project_version(self) -> str:
        field = self.find_field("general", "version")
        version = field.value.replace('"', "")
        return version

    def set_project_version(self, version: str) -> None:
        field = self.find_field("general", "version")
        line = f'{field.key} = "{version}"\n'
        self.lines[field.line_index] = line


# ---------------------------------------------------
# Upgrading the project version
# ---------------------------------------------------


def confirm_upgrade(old_version, new_version):
    print(f"Going to upgrade the project version")
    print(f"  Old version: {old_version}")
    print(f"  New version: {new_version}")
    answer = input(f"Do you want to actually upgrade the project version? (yes/no): ")
    if answer != "yes":
        raise Exception(f"Confirmation canceled")


def upgrade_project_version(args, project_dir):
    project_file_path = f"{project_dir}/fixproj.toml"
    project_file = ProjectFile(filepath=project_file_path)
    old_version = project_file.get_project_version()
    if args.version is None:
        new_version = increment_version(old_version)
    else:
        new_version = args.version
    confirm_upgrade(old_version, new_version)
    project_file.set_project_version(new_version)
    project_file.save()
    if args.commit and new_version != "":
        GitHelper().commit_file(args, project_file_path, new_version)


# ---------------------------------------------------
# Main routine
# ---------------------------------------------------


def parse_args():
    parser = argparse.ArgumentParser(prog="verup")
    parser.add_argument("version", help="version", nargs="?", default=None)
    parser.add_argument("--commit", action="store_true", help="commit", default=False)
    parser.add_argument("--tag", action="store_true", help="add tag", default=False)
    parser.add_argument(
        "--push",
        action="store_true",
        help="push to the remote repository",
        default=False,
    )
    args = parser.parse_args()
    return args


def main():
    args = parse_args()
    project_dir = "."
    upgrade_project_version(args, project_dir)


if __name__ == "__main__":
    main()
