#===========================================================================
# Auteur   : STIRNEMANN Jonas
# Date création : 25/10/2020
#===========================================================================
# Descriptif: Gestion de tableaux Unidimensionnels
#===========================================================================

# coding: utf-8

ENCODING_FORMAT = 'UTF-8'

with open("inputFile.txt", 'r', encoding=ENCODING_FORMAT) as inputFile:
	textInput = inputFile.read()

print(textInput)

textOutput = ''.join(sorted(textInput))

for car in textOutput:
	print(f"Car : {car}  Hex value : {hex(ord(car))}")


with open("outputText.txt", 'w', encoding=ENCODING_FORMAT) as outputText:
	outputText.write(textOutput)



