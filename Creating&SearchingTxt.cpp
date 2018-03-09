/*
This is an example on how you can Create and search for the users class
using the text file that the class code creates when the 
user selects their class whilst the game is being played.
*/



/*
Creates the file
*/

ofstream myfile; //Creates txt doc of class chosen
  myfile.open ("classChoice.txt"); //Creates a file called ClassChoice.txt
  myfile << "Priest\n";
  myfile.close();



/*
Searches the File
*/

ifstream  stream1("classChoice.txt"); //Locates File
    string line ;

    while( std::getline( stream1, line ) )
    {
        if(line.find("Mage") != string::npos) // Will search for Mage in file
        { 
            cout << line << endl; //Print Line that is read in file.
        }
        else if (line.find("Priest") != string::npos)// Will search for Priest in file
        {
            cout << "Priest" << endl;
        }
        else if (line.find("Necromancer") != string::npos)// Will search for Necromancer in file
        {
            cout << "Necromancer" << endl;
        }
        else if (line.find("Warrior") != string::npos)// Will search for Warrior in file
        {
            cout << "Warrior" << endl;
        }
        else if (line.find("Hunter") != string::npos)// Will search for Hunter in file
        {
            cout << "Hunter" << endl;
        }
        
