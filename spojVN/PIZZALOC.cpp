#include<iostream>
using namespace std;

const int MAX_PLACE = 21;
const int MAX_HOUSE = 101;

int NumRest, R;
int NumPlac;
int XPlace[MAX_PLACE], YPlace[MAX_PLACE];

int NumHous;
int XHouse[MAX_HOUSE], YHouse[MAX_HOUSE];

int NumPeop[MAX_HOUSE];
int MaxPeop;
int SumPeop;

int PRest[MAX_PLACE];

int Reach[MAX_PLACE][MAX_HOUSE];
int Count[MAX_PLACE];

void Check(int pos, int numIgnore, int numRestor)
{
    if(pos == NumPlac)
    {
        int SerPeop = 0;
        int Mark[MAX_HOUSE] = {0};

        for(int j = 0; j < NumRest; j++)
        {
            int idRest = PRest[j];

            for(int i = 0; i < Count[idRest]; i++)
            {
                int idHouse = Reach[idRest][i];
                if(Mark[idHouse] == 0)
                {
                    SerPeop += NumPeop[idHouse];
                    Mark[idHouse] = 1;
                }
                if(SerPeop == SumPeop) break;
            }
        }

        if(SerPeop > MaxPeop) MaxPeop = SerPeop;

        return;
    }

    if(MaxPeop == SumPeop) return;

    if(numRestor < NumRest)
    {
        PRest[numRestor] = pos;
        Check(pos + 1, numIgnore, numRestor + 1);
        if(MaxPeop == SumPeop) return;
    }

    if(numIgnore < NumPlac - NumRest)
        Check(pos + 1, numIgnore + 1, numRestor);
}

int main()
{
    ios::sync_with_stdio(false);
 //   freopen("input.txt","r",stdin);

    cin >> NumRest >> R >> NumPlac;
    for(int i = 0; i < NumPlac; i++)
        cin >> XPlace[i] >> YPlace[i];

    SumPeop = MaxPeop = 0;

    cin >> NumHous;
    for(int i = 0; i < NumHous; i++)
    {
        cin >> XHouse[i] >> YHouse[i] >> NumPeop[i];
        SumPeop += NumPeop[i];
        Count[i] = 0;
    }

    for(int j = 0; j < NumPlac; j++)
        for(int i = 0; i < NumHous; i++)
        {
            int temp = (XHouse[i] - XPlace[j])*(XHouse[i] - XPlace[j]) +
                (YHouse[i] - YPlace[j])*(YHouse[i] - YPlace[j]);

            if(temp <= R*R) Reach[j][Count[j]++] = i;
        }

    Check(0, 0, 0);

    cout << MaxPeop << endl;

    return 0;
}
