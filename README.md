XML Tag Validator using Stack (C Language)
Overview

This program checks whether an XML file has properly matched opening and closing tags.

It uses a stack (linked list implementation) to ensure:

Every opening tag <tag> has a matching closing tag </tag>
Tags are closed in the correct order (LIFO principle)
Objective
Practice Data Structures (Stack)
Understand file handling in C
Learn string processing
Apply LIFO (Last In First Out) concept
How the Program Works
Open the XML file (test.xml)
Read the file character by character
When < is found, read the full tag until >
If it is an opening tag, push it into the stack
If it is a closing tag, pop from the stack and compare
After reading the file:
If stack is empty → Valid XML
Otherwise → Invalid XML
Data Structure Used
Stack (Linked List)

Each node stores:

A tag (string)
Pointer to next node

Top → "b" → "a" → NULL

Key Functions
initStack()

Initializes an empty stack

push(Stack S, char *tag)

Adds a tag to the stack

pop(Stack S)

Removes the top tag from the stack

empty(Stack S)

Checks whether the stack is empty

How to Run
Compile
gcc main.c -o xml_validator
Run
./xml_validator
Input File

Create a file named test.xml in the same directory.

Example:

<a>
  <b></b>
</a>
Example Input
Valid XML
<a>
  <b></b>
</a>
Invalid XML
<a>
  <b>
</a>
Output

Valid XML

or

Invalid XML

Limitations
Does not support attributes (<a id="1">)
Does not support self-closing tags (<br/>)
Fixed tag size limitation
Assumes properly formatted XML
Future Improvements
Support attributes in tags
Handle self-closing tags
Improve error reporting with position tracking
Use dynamic memory for scalability
Key Concepts Learned
Stack (Linked List implementation)
File handling in C
String manipulation (strcpy, strcmp)
XML parsing basics
LIFO principle
Author
Name: Hlaing Min Thant
Course: Data Structures (DSA)
Language: C

Conclusion

This project demonstrates how a stack data structure can be used to validate XML structure by ensuring correct nesting and ordering of tags.