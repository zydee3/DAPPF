import re
import os

roots = ["../framework", "../framework/data", "../framework/meta"]
forbidden = ["test", "utility", "data", "meta", "async_wrappers", "event_listeners", "security"]

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
    try:
      if index < len(lines):
        fullFunctionName = lines[index]
        while fullFunctionName[-1] == "{" or fullFunctionName[-1] == " " or fullFunctionName[-1] == "\n":
          fullFunctionName = fullFunctionName[0:len(fullFunctionName)-1]
        fullFunctionName += "\n"
    except:
      print(path)
      print(file)
      functionName = ""

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
      if functionName != "":
        markdown.write(f"#### {functionName}\n")
        markdown.write(f"```cpp\n{fullFunctionName}```\n\n")
        markdown.write(f"{functionDescription}\n")

sidebar = open("_sidebar.md", "w")

sidebar.write("- DAPPF\n  - [About](/)\n  - [Getting Started](confinguration.md)\n\n- Documentation\n")

for root in roots:
  dirs = os.listdir(root)
  websitefiles = os.listdir()

  for d in dirs: 
    if d in forbidden:
      continue

    d_path = f"{root}/{d}"
    if os.path.isfile(d_path):
      continue
    
    files = os.listdir(d_path)
    if len(files) == 0:
      continue

    markdown_name = d + ".md"
    markdown = open(markdown_name, "w")
    markdown.write(f"# {d.capitalize()} API Reference  \n")
    sidebar.write(f"  - [{d.capitalize()}]({markdown_name})\n")

    for file in files:
      if ".cpp" not in file:
        continue
      parseFile(file, d_path, markdown)

      markdown.write(f"<hr>\n\n")

    markdown.close()
