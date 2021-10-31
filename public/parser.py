import re
import os

root = "../framework"

def parseFile(file, path, markdown):

  def parseFunction(lines, index):
    nonlocal functionName
    nonlocal fullFunctionName
    nonlocal functionDescription

    functionDescription = ""

    while index < len(lines) and "*/" not in lines[index]:
      line = lines[index]
      while line[0] == "*" or line[0] == " ":
        line = line[1:]
      functionDescription += f"> {line[:-1]}  \n"
      index += 1
    index += 1
    if index < len(lines):
      fullFunctionName = lines[index]
      while fullFunctionName[-1] == "{" or fullFunctionName[-1] == " " or fullFunctionName[-1] == "\n":
        fullFunctionName = fullFunctionName[0:len(fullFunctionName)-1]
      fullFunctionName += "\n"

    functionName = re.findall(r'[a-zA-Z0-9_]+\(|$',fullFunctionName)[0]
    functionName += ")\n"

  functionName = ""
  fullFunctionName = ""
  functionDescription = ""
  filename = file[:-4]
  rfile = open(f"{path}/{file}")
  lines = rfile.readlines()

  markdown.write(f"## {filename}\n\n")
  for i in range(len(lines)):
    if "/**" in lines[i]:
      parseFunction(lines, i+1)
      markdown.write(f"#### {functionName}\n")
      markdown.write(f"```cpp\n{fullFunctionName}```\n\n")
      markdown.write(f"{functionDescription}\n")


dirs = os.listdir(root)
websitefiles = os.listdir()

sidebar = open("_sidebar.md", "w")

sidebar.write("- DAPPF\n  - [About](/)\n  - [Getting Started](confinguration.md)\n\n- Documentation\n")

for d in dirs: 
  d_path = f"{root}/{d}"
  if os.path.isfile(d_path):
    continue
  
  markdown_name = d + ".md"
  markdown = open(markdown_name, "w")
  markdown.write(f"# {d.capitalize()} API Reference  \n")
  sidebar.write(f"  - [{d.capitalize()}]({markdown_name})\n")
  files = os.listdir(d_path)

  for file in files:
    if ".cpp" not in file:
      continue
    parseFile(file, d_path, markdown)

    markdown.write(f"<hr>\n\n")

  markdown.close()
