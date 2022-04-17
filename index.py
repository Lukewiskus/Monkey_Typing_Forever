originalFile = open("text/words.txt", "r")
newFile = open("text/words_.txt", "a")

#inefficent but it worked lol good for 1 time use i guess

longList = []
unwanted_words = [
"pa", "roc", "eg", "eg", "ne", "aga",
 "nu", "ms", "mr", "re", "els", "baa", "ala", "alb",
 "baa", "ewe", "erg", "dhow", 
]
max = 0
s = ""
for x in originalFile:
    bad = False
    hasApos = False
    x = x.lower()

    for char in x:
        if(char == "#"):
            bad = True
        if(char == "'"):
            hasApos = True
    
    #gets rid of comments
    if(hasApos == True):
        x = x.replace("'","")

    if(bad != True):
        #this takes forever
        if x not in unwanted_words:
            if max > 20000:
                break
            else:
                s = s + x
                max += 1

newFile.write(s)
originalFile.close()
newFile.close()