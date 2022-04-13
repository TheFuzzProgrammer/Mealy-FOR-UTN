#include "AFDS.h"
#ifndef Mealy, Status
#define Mealy AFND::Mealy
#define Status AFND::status
#endif


int main() {

	std::cout << "as1qw2rt3ui4bn5\n\n"; //TRANSITION RULE
	Mealy new_machine(5, false, 0);
	new_machine.set_condition("as5qw3rt1ui2bn3");
	std::cout << new_machine.actual_status().code << " Is the actual status \n";
	std::cout << new_machine.q_status[new_machine.a_status].code << " is where it should go" << "\n";
	std::cout << new_machine.actual_status().code << " Is the actual status \n";
	std::cout << new_machine.translate("aqrub") << " translation for: aqrub  \n";
	std::cout << new_machine.get_word() << " Is the traduction for aqrub \n";
	return 0;
}
