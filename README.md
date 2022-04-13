Implementation: it accepts rules with this format:
    char[3] = {A,B,C}
    WHERE: A=TRANSITION SYMBOL (ACEPTED)
           B=RESULT OF TRANSITION (Symbol added to translated word)
           C=Status Code for the transition (wich status the machine will take after the symbol was procesed)
for every status that the machine will have... so you should initialize this one with the required params.
then, you should set the rules with set_condition().

set_condition():
    Accepts char[ n -> (n/3) == statuses quantity] 
    or std::string (Setted as String on the code, it could be changed to String^ w nmspc System)
    
Writted by fuzz

