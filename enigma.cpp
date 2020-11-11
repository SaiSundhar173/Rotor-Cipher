#include<bits/stdc++.h>
using namespace std;
class Rotor
{
    map<int,string>alphabets={{50,"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
                              {51,"ADCBEHFGILJKMPNOQTRSUXVWZY"},
                              {60,"ACEDFHGIKJLNMOQPRTSUWVXZYB"},
                              {61,"AZXVTRPNDJHFLBYWUSQOMKIGEC"},
                              {70,"AZYXWVUTSRQPONMLKJIHGFEDCB"},
                              {71,"AEBCDFJGHIKOLMNPTQRSUYVWXZ"}};
    char key;
    int rotor;
    string rotor_str;
public:
    Rotor(char key,int rotor)
    {
        this->key=key;
        rotor_str=alphabets[rotor];
        int ind;
        for(int i=0;i<rotor_str.size();i++)
        {
            if(rotor_str[i]==key)
            {
                ind=i;
                break;
            }
        }
        rotor_str=rotor_str.substr(ind,26-ind)+rotor_str.substr(0,ind);
    }
    int get_distance(char ch)
    {
        for(int i=0;i<rotor_str.size();i++)
        {
            if(ch==rotor_str[i])
            {
                return i;
            }
        }
        return -1;
    }
    char rotation(int flag,int distance)
    {
        if(!flag)
        {
            distance=26-distance;
        }
        return rotor_str[distance%26];
    }
};
class Enigma
{
    string key;
    vector<Rotor>rotor;
public:
    Enigma(string key,vector<int>rotor)
    {
        this->key=key;
        for(int i=0;i<3;i++)
        {
            this->rotor.push_back(Rotor(key[i],rotor[i]));
        }
    }
    string encrypt(string text)
    {
        string ans;
        for(int i=0;i<text.size();i++)
        {
            int distance=rotor[i%2].get_distance(text[i]);
            ans.push_back(rotor[2].rotation((i+1)%2,distance));
        }
        return ans;
    }
    string decrypt(string text)
    {
        string ans;
        for(int i=0;i<text.size();i++)
        {
            int distance=rotor[2].get_distance(text[i]);
            ans.push_back(rotor[i%2].rotation((i+1)%2,distance));
        }
        return ans;
    }
};
int main()
{
    string key;
    cout<<"Enter a key"<<endl;
    cin>>key;

    vector<int>rotor;
    cout<<"Enter three rotors"<<endl;
    for(int i=0;i<3;i++)
    {
        int u;
        cin>>u;
        rotor.push_back(u);
    }

    Enigma e(key,rotor);

    string text;
    cout<<"Enter a plain text"<<endl;
    cin>>text;

    string encrypted=e.encrypt(text);
    cout<<encrypted<<endl;

    string decrypted=e.decrypt(encrypted);
    cout<<decrypted<<endl;
    return 0;
}
