#define MAX 100000

int data[MAX] = {93, 181, 245, 214, 315, 36, 185, 138, 216, 295};
int comb[MAX];
int n, m, sum, closest;

void combination(int N, int R, int q)
{
	if (R == 0)
	{
        sum = 0;
		for (int i = q-1; i >= 0; i--)
		{
			sum += comb[i];
		}
        if(sum < m) {
            closest = sum > closest ? sum : closest;
        }
	}
	else if (N < R)
	{
		return;
	}
	else
	{
		comb[R - 1] = data[N - 1];
		combination(N - 1, R - 1, q);
		combination(N - 1, R, q);
	}
}