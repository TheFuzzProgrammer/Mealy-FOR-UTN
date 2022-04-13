#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

namespace mealy {

	struct status {

		std::vector <char[3]> symbols;

		void s_symbol(char _symbol, char _action, char _goes_to) {
			this->symbols[0][0] = _symbol;
			this->symbols[0][1] = _action;
			this->symbols[0][2] = _goes_to;
		}
	};

	class mealy {

		std::vector<status> q_states; // vector[POSITION] is STATUS so vector[POSITION].SYMBOLS{IN, OUT, TRANSITION} where {char, char, char}
		int a_status;				  // ACTUAL STATUS is INDEX of the vector wich is the status where the machine is.
		mealy(int,bool,int);		  // constructor

		private:

		void set_states(int _n) {
			for (int C = 1; C <= _n; C++) {
				status new_status;
				q_states.push_back(new_status);
			}
		}
		bool set_condition(std::string _condition) {
			if (_condition.size() / 3 != q_states.size()) {
				return false;
			}
			else{
				int index_increase = 0;
				for (int C = 0; C <= this->q_states.size(); C++) {
					q_states[C].s_symbol(_condition[0 + index_increase], _condition[1 + index_increase], _condition[2 + index_increase]);
					if (index_increase == 0) {
						index_increase += 4;
					}
					else {
						index_increase =+3;
					}
				}
				return true;
			}
		}
	};
#pragma region CONSTRUCTORS

	mealy::mealy(int _q_states_n, bool _a_state, int _new_status = 0) {

		switch (_a_state) {
			case true:
				this->a_status = rand();
			case false:
				this->a_status = _new_status;
			default:
				this->a_status = rand();
			}
		this->set_states(_q_states_n);

	}
#pragma endregion
}
//Writted by Fuzz