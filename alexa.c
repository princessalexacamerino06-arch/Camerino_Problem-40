#include <stdio.h>

int main(void)
{
	int available = 30;
	int total_assigned = 0;
	int rejected_requests = 0;
	int groups;

	printf("How many student groups will request computers? ");
	if (scanf("%d", &groups) != 1 || groups < 0) {
		printf("Invalid number of groups.\n");
		return 1;
	}

	for (int group = 1; group <= groups; group++) {
		int requested;

		printf("Enter the number of computers requested by group %d: ", group);
		if (scanf("%d", &requested) != 1) {
			printf("Invalid request.\n");
			return 1;
		}

		if (requested >= 0 && requested <= available) {
			available -= requested;
			total_assigned += requested;
			printf("Request accepted. Available computers: %d\n", available);
		} else {
			rejected_requests++;
			printf("Request rejected. Available computers: %d\n", available);
		}
	}

	printf("\nTotal computers assigned: %d\n", total_assigned);
	printf("Remaining computers: %d\n", available);
	printf("Rejected requests: %d\n", rejected_requests);

	return 0;
}
