# Cheating-Hangman
A class project that i could have worked on with a partner, but I chose to work alone. 

# Simple plan (will change)
I'm going to have about 2 classes. 

## Class 1
a class that can get dictionaries and also return a certain number of characters
- for example, if the word is about 5 characters long, it will only return anything that is 5 characters long

## Class 2
A filter system to filter out the words
## OLD IDEA ##
- using regular expressions we will filter the words as so
  - make a new list to hold the words
  - going through a loop of words with the same length of the random word
    - if the word begins with the selected letter, append to the new list
    - if the word ends with the selected letter, append to the new list
    - if the word begins and ends with the selected letter, append to the list
    - if the word begins with the letter. but has another occurrence of the letter in the word, then append to the new list
    - if the word ends with the letter, but there is another occurrence of the letter in the word, then append to the new list
    - if the word the letter anywhere in the middle of the word (not at the beginning or end of the word) then append to the new list
  - ## In short only return words that have the selected letter in the word ##

## NEW PLAN ##
- I had to get the pattern of the words.
- place each pattern into a map called families
- after that, only show words that have the family that has those guessed words into a list
- returns a list of the largest family size mapped
- we will uses this system to include all guesses to have a better idea of which words could be included
  - meaning that all your guesses are possible options for your final result

# Game Logic
Where the whole game logic will go in
- this will include the fundamentals of normal hangman
- has also the system of the cheating system

## THIS PLAN WAS CREATED ON 4/14/26 AND IS SUBJECT TO CHANGE IN THE FUTURE ##
