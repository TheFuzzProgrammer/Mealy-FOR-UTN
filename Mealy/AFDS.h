#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <charconv>
#include "types.h"
#ifndef String, Vector, ToInt
#define String std::string
#define Vector std::vector
#define ToInt Conversions::CharToInteger
#endif


namespace AFND {


	struct status {

		public: char symbols[3];
		public: int code = 0;

		void s_symbol(char _symbol, char _action, char _goes_to) {
			this->symbols[0] = _symbol;
			this->symbols[1] = _action;
			this->symbols[2] = _goes_to;
		}
		void set_code(int _code) {
			this->code = _code;
		}
		String ToString() {
			String temp_str;
			for (int c = 0; c <= 2; c++) {
				temp_str = temp_str + symbols[c];
			}
			return temp_str;
		}

	};



	class Mealy {

		private: const unsigned long long IN = 0, OUT = 1, TRA = 2; // Indexes US LL For prevent overflow

		public:

			Vector<status> q_status; // vector[POSITION] is STATUS so vector[POSITION].SYMBOLS{IN, OUT, TRANSITION (N OR STATUS)} where {char, char, char}
			int a_status;				  // ACTUAL STATUS is INDEX of the vector wich is the status where the machine is.
			String word = "", traduction = "";
			Vector<String> transition_func;

		public:	Mealy(int, bool, int);		  // constructor
		
		

		private: void set_states(int _n) {
					for (int C = 1; C <= _n; C++) {
						status new_status;
						q_status.push_back(new_status);
					}
				}

		public:	bool set_condition(String _condition) {
					if (_condition.size() / 3 != q_status.size()) { //rejects invalid transition functions
						return false;
					}
					else {
						int index_increase = 0;

						for (int C = 0; C < this->q_status.size(); C++) {
						
							switch (index_increase) {
								case 0: if (C > 0) index_increase += 3 ;
									break;
								default: index_increase += 3;
							}
							q_status[C].s_symbol(_condition[IN + index_increase],
													_condition[OUT + index_increase],
														_condition[TRA + index_increase]);

							q_status[C].set_code(C+1);
						}
						return true;
					}
				}

		private: int update(char _symbol) {
					for (int c = 0; c <= q_status.size()-1; c++) {
						if (ToInt(this->q_status[a_status].ToString()[2]) == this->q_status[c].code) {
							// if you want a log //std::cout << "ACTUAL STATUS CHANGED FROM " << this->q_status[a_status].code;
							a_status = c;
							// if you want a log //std::cout << " TO " << this->q_status[a_status].code << "\n";
							return c;
						}
						else {
							if (c == q_status.size()-1) {
								return -1;
							}
						}
					}
					}

		public: String get_word() {
					return this->word;
				}

		public: status actual_status() {
					return this->q_status[a_status];
				}
				String translate(String _word) {
					for (int c = 0; c < _word.size(); c++) {
						switch (this->q_status[a_status].ToString()[0] == _word[c]) {
						case true:
							this->word = this->word + this->q_status[a_status].ToString()[1];
							this->update(_word[c]);
							
								break;
							default:
								break;
						}
					}
					return this->word;
				}
	};
#pragma region CONSTRUCTORS

	Mealy::Mealy(int _q_states_n, bool _a_state, int _new_status = 0) {

		switch (_a_state) {
		case true:
			this->a_status = rand();
		case false:
			this->a_status = _new_status;
		}
		this->set_states(_q_states_n);

	}

#pragma endregion
}
//Writted by Fuzz