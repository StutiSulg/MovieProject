1. Describe the state of your program, exactly what works and what does not work. 
    My program is able to take in data of customers and movies and correctly place them in hash tables and binary trees. My program is also able to correctly pull the correct customer and movie item to execute each transaction requested. 

2. List your hash table(s): briefly what they are used for and file found in. 
    (Include any factories that are essentially hash tables.)
    -- Factory class contains 2 Hashtables. One representing a hashtable for empty itemFactory, and another hashtable representing an tranFactory hashtable. 
    -- Inventory class contains one hashtable that contains BinTrees keyed to characters of Movie Codes

3. State which file and which function you read the movie data, high level function call, 
    i.e., how/where it gets into your movie collections. 
   
    Movie data is read in the Manger class through the function called initializeStore(istream &) and creates the approriate item by calling the createItem function in the Factory class. This new and empty Item object(ClassicMovie, DramaMovie, ComedyMovie) is then sent pieces of istream by the manager class where the item is initialized by using the istream. The item object is sent back to the Manager class where it is then placed into the inventory class that holds all the items in the appropriate binary tree seperated in a hash table through the addItem function. 


4. State which file and which function you read the command data, high level function call, 
    i.e., how/where you perform the commands/transactions. 

    The command data is read in the Manager class through the fuction called runCommands which sends pieces of istream to Factory to create an empty Item object. Then the manager function sends other pieces of the istream to the new empty Item object thorugh initCompObje which initializes the object up to a comparable level with items of it's own genera. Next, the manager class then compares this half baked initialized object to items stored in Inventory to find the correct item a transaction needs to be done on. If item is found sucessfully the half baked initialized object is deleted and a pointer to the acutal item object is stored and sent to the approriate Transaction object created by the Factory class. The Transaction object uses a function called setData that takes the pointer to the apporitate item found as well as the approriate customer(which gets found in the runCommand function) and stores that data inside of the transaction object. 

    If the Transaction object does not produce any errors then executeTran is called for that Transaction object where the transaction will occur. 


5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.) 
    If you feel they do not violate the open-closed design principle, explain. 

    There are a lot of if-else statements placed in the runCommand function in the Manager class to find the errors that the text files might cause. But I don't believe this is a violation of the open-closed design principle since it doens't affect you being able to add more types of items or transaction types to this program. 

6. Describe anything you are particularly proud of ... 

    My double hashtables in one factory class. I thought this was a pretty different idea. Since the sole purpose of it is to produce empty objects, the one factory can produce all the empty items and transaction objects you need! 