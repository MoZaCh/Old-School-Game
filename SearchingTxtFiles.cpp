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
        
