#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> maximum(vector<vector<int>>benzin)
{   
    pair<int, int> eredmeny;

    int max = 0;
    int id = 0;
    for (int i = 0; i < benzin.size(); i++)
    {
        if (max<benzin[i][2])
        {
            max = benzin[i][2];
            id = benzin[i][0];
        }
    }
    eredmeny.first = id;
    eredmeny.second = max;

    return eredmeny;
}

int main() {
    int K, N, B, L;
    cin >> K;
    cin >> N;
    cin >> B;
    cin >> L
        ;
    vector<vector<int>> lista(N, vector<int>(3));
        
    
    for (int i = 0; i < N; i++)
    {
        lista[i][0] = i;
        cin >> lista[i][1] >> lista[i][2];
    }

    
    /** /
    cerr << "rendezes elott:\n";
    for (auto& triplet : lista)
        cout << triplet[0] << ". " << triplet[1] << " - " << triplet[2] << endl;

    /**/

    int hatotav = (B * 100) / L;

    int tankolva = -1;
    int szamlalo = 0;
    int i = 0;

    while (hatotav<K)
    {
        vector<vector<int>> benzin(N, vector<int>(3));

        i = tankolva+1;
        while (i<N && lista[i][1] < hatotav)
        {
                

            benzin[i] = lista[i];
            i++;
            cout << i << endl;
            cout << hatotav << endl;
            cout<<"----------"<<endl;

        }
      
        pair<int,int>max = maximum(benzin);
           
        
        hatotav+= (max.second* 100) / L;

        tankolva += max.first;
   
       
        szamlalo++;
  
    }
    cout << szamlalo<<endl;

    

}