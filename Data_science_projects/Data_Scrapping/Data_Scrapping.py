
# coding: utf-8
# Python program to perform the count of a wikipedia xml dump file
# By Ater Akrofi

import xml.etree.ElementTree as etree
import itertools
import re
import string

#Create containers for lists
title = []
abstract = []
anchor= []


def main():
    #Parse XML file using Element tree
    tree = etree.parse('test.xml')
    root = tree.getroot()

    #Acquire text from xml tags 
    for child in root:
        title.append(child.find('title').text)
        abstract.append(child.find('abstract').text)
           
    for anch in root.iter('sublink'):
            anchor.append(anch.find('anchor').text)
                   
        
if __name__ == "__main__": main()
    

#Remove empty spaces from lists
title_list = [x for x in title if x is not None]
anchor_list = [x for x in anchor if x is not None]
abstract_list = [x for x in abstract if x is not None]


# Remove punctuation from lists
punct_title = [''.join(c for c in s if c not in string.punctuation) for s in title_list]
punct_anchor = [''.join(c for c in s if c not in string.punctuation) for s in anchor_list]
punct_abstract = [''.join(c for c in s if c not in string.punctuation) for s in abstract_list]

#Convert lists to wordlists
wl_title = [word for line in punct_title for word in line.split()]
wl_abstract = [word for line in punct_abstract for word in line.split()]
wl_anchor = [word for line in punct_anchor for word in line.split()]

#Merge Lists
Merged_List = itertools.chain(wl_title,wl_abstract,wl_anchor)

List = list(Merged_List)

#Print Count of Stopwords
count1 = List.count("is")
count2 = List.count("about")
count3 = List.count("and")
count4 = List.count("any")

print "Some StopWords"
print "Instances of 'is'   : %s" % count1
print "Instances of 'about' : %s" % count2
print "Instances of 'and' : %s" % count3
print "Instances of 'any' : %s" % count4





