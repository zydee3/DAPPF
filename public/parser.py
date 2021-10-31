import re

def parseFile(file, path):

  def parseFunction(lines, index):
    nonlocal functionName
    nonlocal fullFunctionName
    nonlocal functionDescription

    functionDescription = ""

    while index < len(lines) and "*/" not in lines[index]:
      line = lines[index]
      while line[0] == "*" or line[0] == " ":
        line = line[1:]
      functionDescription += line
      index += 1
    index += 1
    if index < len(lines):
      fullFunctionName = lines[index]
      while fullFunctionName[-1] == "{" or fullFunctionName[-1] == " " or fullFunctionName[-1] == "\n":
        fullFunctionName = fullFunctionName[0:len(fullFunctionName)-1]
      fullFunctionName += "\n"

    functionName = re.findall(r'[a-zA-Z0-9_]+\(.*\)|$',fullFunctionName)[0]
    functionName += "\n"

  functionName = ""
  fullFunctionName = ""
  functionDescription = ""
  filename = file[:-4]
  rfile = open(path + file)
  lines = rfile.readlines()

  for i in range(len(lines)):
    if "/**" in lines[i]:
      parseFunction(lines, i+1)
      print(functionName)
      print(fullFunctionName)
      print(functionDescription)
  print(filename)

parseFile("packet_reader.cpp", "../framework/meta/")


