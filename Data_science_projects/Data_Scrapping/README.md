Ater Akrofi
ST ID : 10882731
Report on Implementation: 
Python program to count stop words from a Wikipedia xml dump 

1.	INTRODUCTION
The goal of this implementation project was to create a program that can provide the count of stop words instances from a downloaded Wikipedia xml file. The XML dump file was 82MB in size and contained abstracts of several Wikipedia pages. The file was downloaded from https://dumps.wikimedia.org/enwiki/20170301/ and saved as test.xml

2.	APPROACH
First Step: Parsed XML file into an Element Tree
The element tree is a container object that makes it possible to store and represent XML tags as parent, child, neighbors or grandparent nodes.
With Element tree, it was possible to select title and abstract tags as child nodes and anchor tags as neighbor nodes. The data from these tags were stored as raw python lists

Second Step: Removed empty spaces from raw lists
The raw lists contained empty spaces that prevented further processing on these lists. A simple condition was set to prevent appending empty spaces to lists 

Third Step: Removed punctuation
Further processing was done to remove punctuation from the saved lists. This was achieved using a combination of “join” and punctuation  

Fourth step: Convert lists to Wordlist
The python lists contained in some cases full sentences or two or more words represented as a single list item. Using the split() function these sentences were separated into individual wordlists. 

Fifth Step: Merge the 3 lists as one
By now we have 3 lists (title, anchor and abstract) which would need to be merged into a single list before performing the count of stop words. This method was vital to perform the next step of counting the stop words
Final Step: Run count
The count () method was used to perform the count of the Wikipedia page dump

3.	RESULTS
Screenshot of output file

4.	CHALLENGES
The processing of the 82MB Wikipedia xml file took approximately 45 seconds to output results. Considering this was a relatively small file, it may take several minutes to run bigger files.  

5.	CONCLUSION
This method of determining the count of stop words was not efficient in terms of execution time but effective in solving the problem. 
