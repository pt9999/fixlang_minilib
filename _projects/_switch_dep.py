#!/usr/bin/env python3

# switch `path` and `git` for dependencies with matching name.
#
# 指定したプロジェクトの fixproj.toml を更新する。
# 具体的には、fixproj.tomlに記載された依存先プロジェクトのうち、
# `name` が指定したパターンにマッチするものについて、
# ソース(`path` または `git`) の種別を更新する。
#
# Usage: 
#    python3 _switch_dep.py [-h] [-n NAME] [-t TYPE] [projects ...]
# Example:
#    python3 _switch_dep.py fixlang-minilib-math -n "common|binary" -t git 

import os
import os.path
import argparse
import re

def to_local_path(name, project_dir):
    path = os.path.relpath(os.curdir, start=project_dir)
    path = os.path.join(path, "fixlang-" + name)
    return path

def to_git_url(name):
    return "https://github.com/pt9999/fixlang-" + name + ".git"

def update_fixproj_toml(args, project_dir: str, input_lines: list[str]) -> list[str]:
    output = []
    dep_section = False
    dep_name = ""
    dep_source = False
    for line in input_lines:
        section = line.strip()
        if section.startswith("["):
            dep_section = (section == "[[dependencies]]")
            dep_name = ""
            dep_source = False
            output.append(line)
            continue
        if (not dep_section) or ("=" not in line):
            output.append(line)
            continue
        key, value = line.split("=", 1)
        key = key.strip()
        value = value.strip()
        if key == "name":
            value = value.replace("\"", "")
            if re.search(args.name, value):
                dep_name = value
            output.append(line)
            continue
        if dep_name == "":
            output.append(line)
            continue
        if key.startswith("#"):
            key = key.replace("#", "").strip()
        if key == "path" or key == "git":
            if dep_source == False:
                key = ("" if args.type == 'path' else "# ") + "path"
                value = '"' + to_local_path(dep_name, project_dir) + '"'
                output.append(key + " = " + value + "\n")
                key = ("" if args.type == 'git' else "# ") + "git"
                git_url = to_git_url(dep_name)
                value = "{ url = \"" + git_url + "\" }"
                output.append(key + " = " + value + "\n")
                dep_source = True
            continue
        else:
            output.append(line)
            continue
    return output

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
                    prog='switch_dep')
    parser.add_argument('projects', nargs='*', help='target projects to change', default=['fixlang-minilib-common'])
    parser.add_argument('-n', '--name', help='regexp pattern for `name`', default='^minilib-.*$')
    parser.add_argument('-t', '--type', help='source type (`git` or `path`)', default='git')
    args = parser.parse_args()
    return args
    

if __name__ == "__main__":
    args = parse_args()

    for project_dir in args.projects:
        update_project(args, project_dir)
