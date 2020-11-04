#===========================================================================
# Auteur   : STIRNEMANN Jonas
# Date création : 25/10/2020
#===========================================================================
# Descriptif: Gestion de tableaux Unidimensionnels
#===========================================================================

# coding: utf-8



# with open("inputFile.txt", 'r', encoding=ENCODING_FORMAT) as inputFile:
# 	textInput = inputFile.read()

# print(textInput)

# textOutput = ''.join(sorted(textInput))

# for car in textOutput:
# 	print(f"Car : {car}  Hex value : {hex(ord(car))}")


# with open("outputText.txt", 'w', encoding=ENCODING_FORMAT) as outputText:
# 	outputText.write(textOutput)



def createAlphabeticallySortedFileFromFile(fileIn):
	"""Sort a file in Alphabeticall order and put it in an other file

	Args:
		file (string): file name of the file you want sorted
	"""
	ENCODING_FORMAT = 'UTF-8'
	with open(fileIn, 'r', encoding=ENCODING_FORMAT) as inputFile:
		textInput = inputFile.read()
  
	textOutput = ''.join(sorted(textInput))

	with open("alphabeticallySorted" + fileIn, 'w', encoding=ENCODING_FORMAT) as outputText:
		outputText.write(textOutput)

def createOccurenceSortedFileFromFile(fileIn):
	"""Sort a file in Number of occurence and put it in an other file
	Args:
		file (string): file name of the file you want sorted
	"""
	from collections import Counter

	ENCODING_FORMAT = 'UTF-8'
	with open(fileIn, 'r', encoding=ENCODING_FORMAT) as inputFile:
		textInput = inputFile.read()

	textOutput = ""
 	#Counter(textOutput).most_common() returns a dictionnary of caracters sorted by occurence
	for car in Counter(list(textInput)).most_common(): 
		print(car[0] * car[1], end="")
		textOutput += str(car[0] * car[1])
		print(textOutput)
	

	with open("occurenceSorted" + fileIn, 'w', encoding=ENCODING_FORMAT) as outputText:
		outputText.write(textOutput)

# createAlphabeticallySortedFileFromFile("inputFile.txt")
createOccurenceSortedFileFromFile("inputFile.txt")