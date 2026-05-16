# include <stdio.h>
# include <stdbool.h>

bool premise1(bool p, bool q, bool r){
	return (!r || (!p || q));
}

bool premise2(bool p, bool r){
	return (p || !r);
}

bool conclusion(bool  r, bool q){
	return !(!r || q);
}

int main(){
	bool p, q, r;

	printf("Checking the validity of the premises...\n");

	for (p = false; p <= true; p ++){
		for (q = false; q <= true; q ++){
			for (r = false; r <= true; r ++){
				if (premise1(p, q, r) && premise2(p, r) && !conclusion(r, q)){
					printf("Invalid argument found with the following assignment\n");
					printf("p = %s, q = %s, r = %s\n", p? "true" : "false", q? "true" : "false", r? "true" : "false");
					return 0;
				}
			}
		}
	}
	printf("The argument is valid");


	return 0;
}
