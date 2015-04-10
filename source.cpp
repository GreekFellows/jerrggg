#include <iostream>
#include <string>

int main() {
	std::cout << "    jerrggg.\n\n";

	float hung[3] = { 100, 100, 100 };
	float thir[3] = { 100, 100, 100 };
	float kp[3] = { 5, 5, 5 };
	float sp[3] = { 5, 5, 5 };
	float hp[3] = { 1000, 1000, 1000 };
	std::string nomina[3] = { "food", "drink", "aid kit" };

	int supply[3] = { 10, 20, 20 };
	int isupply[3][3] = { { -1, 0, 0 }, { 0, -1, 0 }, { 0, 0, -1 } };
	bool alive[3] = { 1, 1, 1 };

	int iter = 0;
	while (alive[0] || alive[1] || alive[2]) {
	__:

		if (hp[iter] < 0) {
			std::cout << "\n\n    person " << iter << " is dead.";
			iter++;
			iter %= 3;
			continue;
		}

		hung[iter] -= 5;
		thir[iter] -= 8;
		kp[iter] -= 0.2;
		sp[iter] -= 0.2;

		if (hung[iter] < 50 || thir[iter] < 50) {
			hp[iter] -= 5;
		}

		float hfac = 1;
		float tfac = 1;
		float kfac = 1;

		if (kp[iter] >= 4) {
			tfac *= 1.0f;
		}
		else if (kp[iter] >= 3) {
			tfac *= 0.9f;
		}
		else if (kp[iter] >= 2) {
			tfac *= 0.8f;
		}
		else if (kp[iter] >= 1) {
			tfac *= 0.5f;
		}
		else if (kp[iter] >= 0) {
			tfac *= 0.4f;
		}

		if (thir[iter] < 40) {
			hfac *= 0.5f;
		}

		if (hung[iter] < 40) {
			kfac *= 0.5f;
		}

		std::cout << "\n\n    person " << iter << ", you are currently:\n    HUNG: " << hung[iter] << "\n    THIR: " << thir[iter] << "\n    HP: " << hp[iter] << "\n    KP: " << kp[iter] << "\n    SP: " << sp[iter] << "\n\n    you have:\n    food: " << isupply[iter][0] << "\n    water: " << isupply[iter][1] << "\n    aid kits: " << isupply[iter][2] << "\n\n    your owned supply is " << nomina[iter] << " and you have " << supply[iter] << ".\n\n";

		int choice;
		std::cout << "    0 to trade, 1 to sleep, 2 to speak, 3 to consume.\n >> ";
		std::cin >> choice;

		if (choice == 0) {
			int pchoice;
			std::cout << "    pick a person to trade from 0, 1 and 2.\n >> ";
			std::cin >> pchoice;

			int noffer = 0;
			std::cout << "    name how many " << nomina[iter] << "s you are offering.\n >> ";
			std::cin >> noffer;

			int nget = 0;
			std::cout << "    name how many " << nomina[pchoice] << "s you want.\n >> ";
			std::cin >> nget;

			bool offeracc = true;
			std::cout << " >> whether the offer is accepted (0 or 1): ";
			std::cin >> offeracc;

			if (offeracc) {
				std::cout << "    offer accepted.\n";
				isupply[iter][pchoice] += nget;
				supply[pchoice] -= nget;
				isupply[pchoice][iter] += noffer;
				supply[iter] -= noffer;
			}
			else {
				std::cout << "    offer failed.\n";
			}
		}
		else if (choice == 1) {
			std::cout << "    good night bitches!\n";
			sp[iter]++;
			if (sp[iter] > 5) sp[iter] = 5;
		}
		else if (choice == 2) {
			int talkstop;
			std::cout << " >> type anything and hit return to stop talking.";
			std::cin >> talkstop;
		}
		else if (choice == 3) {
			int cchoice;
			std::cout << "    what to consume? 0 for food, 1 for drink, 2 for aid kits.\n >> ";
			std::cin >> cchoice;

			if (cchoice == 0) {
				if (iter == cchoice) {
					supply[iter]--;
				}
				else {
					isupply[iter][cchoice]--;
				}
				hung[iter] += hfac * 20;
				if (hung[iter] > 100) hung[iter] = 100;
			}
			else if (cchoice == 1) {
				if (iter == cchoice) {
					supply[iter]--;
				}
				else {
					isupply[iter][cchoice]--;
				}
				thir[iter] += tfac * 20;
				if (thir[iter] > 100) thir[iter] = 100;
			}
			else if (cchoice == 2) {
				if (iter == cchoice) {
					supply[iter]--;
				}
				else {
					isupply[iter][cchoice]--;
				}
				kp[iter] += kfac;
				if (kp[iter] > 5) kp[iter] = 5;
			}
		}

		iter++;
		iter %= 3;

		goto __;
	}

	return 0;
}