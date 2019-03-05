import xml.etree.ElementTree as ET
import sys


ET.register_namespace('', "http://www.srcML.org/srcML/src")

#creates the tree from the xml document
tree = ET.parse(sys.argv[1])

#retrieve the root node of the tree
root = tree.getroot()

#Add before tag, namespace
#{http://www.srcML.org/srcML/src}

#iterate through every element (depth first)
for elem in root.iter():

	if elem.tag == "{http://www.srcML.org/srcML/src}name":
		if elem.text == "String":
			elem.text = "TACO"


#writes the new modified tree as an xml file to the provided file name
tree.write(sys.argv[2])

