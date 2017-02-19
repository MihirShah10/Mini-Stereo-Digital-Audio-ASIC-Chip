#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <stdlib.h>
#include<math.h>

using namespace std;

string input_s,input_ss,input_bin;
bitset<40> x_input_final;
bitset<40> input_bin_24bit[1024]={};

string rj_s,rj_ss,rj_bin;
string rj_bin_8bit[16]={};

string coeff_s,coeff_ss,coeff_bin;
string coeff_bin_9bit[159]={};

string u_j; 

int n;
int f_range;

string t="10";
long long sum,sum_signed,sum_dec,sum_rj;

long long coeff_value[159]={};
long long rj_value[15]={};

long long coeff_grp_rj[25][25]={};

int rj_beg;

bitset<40> u[25]={};
bitset<40> u_40[25]={};

bitset<40> final_result[512]={};

string input[512]={

"0xC48B",
"0xCEAD",
"0xC747",
"0x93B7",
"0xDDA7",
"0xC760",
"0x5DFC",
"0x8817",
"0x86D8",
"0x3498",
"0xB570",
"0x366E",
"0xDB45",
"0x20B6",
"0x2F04",
"0xFB27",
"0x20AA",
"0xDA4F",
"0x8EEB",
"0xB61F",
"0x39D5",
"0x75AA",
"0x7AB1",
"0x4C2A",
"0x312A",
"0x4744",
"0xFEB1",
"0x268D",
"0xB41F",
"0x6B4C",
"0x0A9C",
"0xB182",
"0x94C0",
"0x3F27",
"0xF2F9",
"0xDDB7",
"0x482D",
"0xE7ED",
"0xEEA0",
"0x9FCE",
"0x6817",
"0xC7EA",
"0x983E",
"0x70DF",
"0x3247",
"0x0D1E",
"0x71D4",
"0xCBF2",
"0x0817",
"0x25BE",
"0x5C37",
"0xB286",
"0xF0F6",
"0x42B0",
"0x2092",
"0x2A0C",
"0x13E8",
"0xDC13",
"0xEBDF",
"0xBB6C",
"0x3E04",
"0x2DB5",
"0xCA72",
"0xF17F",
"0x64F5",
"0xB39A",
"0x326F",
"0xDD94",
"0x1A7A",
"0xB17C",
"0x7A4E",
"0x95EB",
"0x1AE6",
"0xAD46",
"0x5F5E",
"0xAF3D",
"0xC1A0",
"0xF397",
"0x7E3F",
"0xCA32",
"0x90A3",
"0x1145",
"0xDD67",
"0x06E9",
"0xAFFF",
"0x5AD8",
"0x639E",
"0x8774",
"0x6556",
"0x630B",
"0x5C82",
"0xF559",
"0xA161",
"0x884E",
"0xF603",
"0xFF12",
"0x7569",
"0x6847",
"0xC6E8",
"0xD48E",
"0x95CE",
"0x654C",
"0x4348",
"0xA8AE",
"0xDC83",
"0x25EA",
"0x4A12",
"0x35C8",
"0xC890",
"0x1462",
"0x9986",
"0x3727",
"0xF98E",
"0xE026",
"0x54B9",
"0xEF8A",
"0xB62F",
"0xFB60",
"0x8315",
"0xA1A1",
"0x68B4",
"0x1C6C",
"0x91D7",
"0x1693",
"0x1C74",
"0xBE59",
"0xCE8F",
"0x1B7A",
"0x055C",
"0xA06C",
"0xEEA4",
"0x00E5",
"0xF869",
"0x449D",
"0x89CD",
"0x1A55",
"0xEF30",
"0x7018",
"0x9999",
"0x41C1",
"0x8757",
"0xAFBD",
"0xFFE8",
"0x5312",
"0x8219",
"0xD1A0",
"0xFE6F",
"0xAFA7",
"0x45C6",
"0x678A",
"0xBE38",
"0xBAD3",
"0x5A40",
"0x4876",
"0xCA1F",
"0x5E5A",
"0xF07F",
"0x0F15",
"0x9357",
"0x86F8",
"0x560E",
"0x9A4B",
"0xEBE3",
"0xA3D9",
"0x848C",
"0x8CB0",
"0x8A1D",
"0x2A22",
"0x922C",
"0xCC0F",
"0x8D33",
"0x1467",
"0x3E35",
"0x05EA",
"0xF2A5",
"0x5C32",
"0x6B83",
"0x24F4",
"0x1DC8",
"0x8583",
"0x9D04",
"0xDD95",
"0x5646",
"0x124A",
"0x7E3C",
"0x266A",
"0x489B",
"0x0BEE",
"0x5BC1",
"0xB9C3",
"0x849A",
"0x7FCA",
"0xA7C0",
"0x9623",
"0xFCE6",
"0xFCAB",
"0x7776",
"0x7FC3",
"0x8879",
"0x1854",
"0x05B8",
"0x7B10",
"0x6520",
"0xECFA",
"0x2E6B",
"0x5428",
"0xB0FD",
"0x94C7",
"0xF40C",
"0x1961",
"0xF004",
"0xB15B",
"0xFC2A",
"0x9DC2",
"0x8A7F",
"0xE747",
"0x11E7",
"0xF687",
"0x4A8A",
"0x5F90",
"0x9F7B",
"0xFEA1",
"0xE198",
"0x4632",
"0x39B1",
"0xD534",
"0x61EC",
"0x4B9A",
"0x1367",
"0x5D18",
"0xC220",
"0x252B",
"0x8912",
"0xBC59",
"0x61A1",
"0x0BBA",
"0x9638",
"0xDEB7",
"0x7C31",
"0x3A12",
"0x5EF5",
"0xF127",
"0xB764",
"0x7371",
"0xA477",
"0xE74F",
"0x9A23",
"0x7B08",
"0x5481",
"0xF80D",
"0x102D",
"0x997F",
"0xFBEC",
"0x1DF1",
"0xEA91",
"0x1B6F",
"0x4A21",
"0x96BF",
"0x5A35",
"0xD1E6",
"0x98A0",
"0x64EF",
"0x7852",
"0x90E7",
"0x5C7C",
"0xD02C",
"0xC1F5",
"0xB0E8",
"0xB6DD",
"0xE2D8",
"0x9380",
"0x8F52",
"0xE77C",
"0xEB86",
"0xB227",
"0x0C04",
"0xD52B",
"0xFC7E",
"0xC673",
"0x0DCF",
"0x884B",
"0x6C3D",
"0xDBC2",
"0xF9FB",
"0xB053",
"0x56F2",
"0xDFC5",
"0x3EC2",
"0x1C50",
"0x1903",
"0x2801",
"0xCDD0",
"0x4460",
"0xD686",
"0xEB4F",
"0x99C9",
"0xC035",
"0xF5C8",
"0xC65C",
"0x1CC2",
"0xCF98",
"0xA1CA",
"0x372A",
"0xD2C7",
"0xD1E3",
"0x47BE",
"0x228D",
"0xBB54",
"0xCD86",
"0x1B8E",
"0x4FAE",
"0xDDDC",
"0xEC83",
"0x9356",
"0xE98B",
"0xC045",
"0xFCF3",
"0xEAE5",
"0x0175",
"0xF069",
"0xEE7F",
"0x9E40",
"0x0991",
"0x7F97",
"0x59E6",
"0xF21F",
"0x5A58",
"0x8010",
"0xF57E",
"0x6D6E",
"0xAE17",
"0x8D8B",
"0x20AB",
"0x59CD",
"0xA66F",
"0x42B1",
"0x5C6A",
"0x4610",
"0x46D6",
"0xC0A1",
"0xCEC9",
"0x84C0",
"0x7414",
"0x2B6D",
"0xC16B",
"0xAC98",
"0x7CC7",
"0x2D9C",
"0x2109",
"0x1809",
"0x8FE0",
"0x70A6",
"0x01EC",
"0x66B6",
"0x3F24",
"0x277B",
"0x1675",
"0xF9F9",
"0x05AB",
"0x86FC",
"0x3995",
"0x775C",
"0xBC64",
"0x4580",
"0xE955",
"0x4C21",
"0x2390",
"0x2250",
"0xC64F",
"0x26BB",
"0x5E42",
"0x5C2C",
"0x1733",
"0x7852",
"0x75E6",
"0x38C4",
"0x4543",
"0xF743",
"0xD4B6",
"0x803F",
"0x5ED7",
"0x209D",
"0xC946",
"0xFFB8",
"0x93D9",
"0xAFA6",
"0x0AFA",
"0x06BC",
"0xBB4A",
"0x2954",
"0x2C8B",
"0xEACD",
"0xCEBC",
"0x54D4",
"0x2D85",
"0x83E2",
"0x6AD6",
"0xBA06",
"0xEBCC",
"0xAFE5",
"0x51D4",
"0x29FF",
"0xAA12",
"0xCD34",
"0xE804",
"0x3586",
"0x9362",
"0x4320",
"0xBA49",
"0xB598",
"0x2F99",
"0xF971",
"0xF49C",
"0x42E4",
"0xF0E8",
"0xDBDF",
"0xE686",
"0xBC4F",
"0xA853",
"0x5B9B",
"0x88A7",
"0xC470",
"0x1035",
"0xECC4",
"0xF332",
"0x4215",
"0x42BA",
"0x88F2",
"0xE36F",
"0xE1BD",
"0x4063",
"0x2BAF",
"0x3C38",
"0x8E1C",
"0x6B85",
"0x55F9",
"0x827C",
"0xFD9B",
"0x0CCA",
"0x8CC1",
"0x5FBF",
"0x25D5",
"0xCFAF",
"0xD86F",
"0x2198",
"0xBE1B",
"0x4304",
"0x465C",
"0x3A31",
"0xCAF1",
"0x5B70",
"0x6656",
"0xBECB",
"0x098E",
"0xF0EA",
"0xCC20",
"0xE838",
"0x8360",
"0x3C41",
"0x92EF",
"0x955E",
"0x0385",
"0x6195",
"0xD5EE",
"0xC7BB",
"0x9653",
"0xE0DB",
"0x34BB",
"0x24DC",
"0x10D1",
"0x225D",
"0x54E8",
"0x75E4",
"0x873C",
"0xF338",
"0x5E7B",
"0x270B",
"0xD584",
"0x02DC",
"0x7F6E",
"0xCD1C",
"0x1ACC",
"0x6290",
"0x672F",
"0x9CF6",
"0x39ED",
"0x0CEB",
"0xCB21",
"0xED0C",
"0x56F3",
"0x5A5C",
"0xE31A",
"0xBFE6",
"0x5E9F",
"0x8EA3",
"0xEDE3",
"0x339D",
"0x80E3",
"0x4955",
"0xA8BB",
"0x0E62",
"0xAC69",
"0x145C",
"0xDAD4",
"0x3AF8",
"0x1B0D",
"0xDB74",
"0xCAD4",
"0x4536",
"0xC65E",
"0x6DB0",
"0xC655" };

string input_neg[512]={};

string input_fs[1024]={};

bitset<40>* input_bin_24bit_ptr= input_bin_24bit + 512;

bitset<40> one_comp(string("0000000000000000000000010000000000000000"));

bitset<40> zero_uj(string("0000000000000000000000000000000000000000"));

bitset<40> one_uj(string("1000000000000000000000000000000000000000"));

bitset<40> uj_compensate_neg(string("0000000000000000000000001111111111111111"));

bitset<40> add_result(string("0000000000000000000000000000000000000000"));
bitset<40> carry_comp(string("0000000000000000000000000000000000000000"));
bitset<40> carry(string("0000000000000000000000000000000000000000"));

string add_result_str;
string u_j_present_str, u_j_past_str;

string rj[]={"0x0B",    "0x0F",    "0x0E",    "0x0D",    "0x08",    "0x0D",    "0x0D",    "0x06",    "0x05",    "0x06",    "0x04",    "0x06",    "0x09",    "0x0B",    "0x14",    "0x05"
};

string coeff[]={"0x038",    "0x18C",    "0x00F",    "0x096",    "0x16A",    "0x130",    "0x110",    "0x013",    "0x14F",    "0x1F1",    "0x0FA",    "0x08E",    "0x1FC",    "0x1B0",    "0x13E",    "0x0CF",    "0x0EE",    "0x021",    "0x1AF",    "0x04C",    "0x0A5",    "0x076",    "0x0EB",    "0x13E",    "0x0A8",    "0x055",    "0x17A",    "0x078",    "0x0B4",    "0x03D",    "0x0B7",    "0x1DD",    "0x169",    "0x16C",    "0x1F3",    "0x0E1",    "0x0B2",    "0x14E",    "0x1D3",    "0x0F8",    "0x14D",    "0x1FF",    "0x170",    "0x002",    "0x04A",    "0x1B0",    "0x17E",    "0x115",    "0x132",    "0x1F9",    "0x15D",    "0x024",    "0x104",    "0x1A3",    "0x1BC",    "0x007",    "0x01A",    "0x1E4",    "0x0C3",    "0x095",    "0x0AF",    "0x1F7",    "0x08C",    "0x1C6",    "0x19C",    "0x0FC",    "0x00C",    "0x0FB",    "0x134",    "0x1E9",    "0x1AA",    "0x176",    "0x01C",    "0x075",    "0x0CC",    "0x14A",    "0x1B1",    "0x142",    "0x1B6",    "0x1B8",    "0x1BB",    "0x09F",    "0x1FC",    "0x027",    "0x134",    "0x0D1",    "0x00F",    "0x189",    "0x130",    "0x199",    "0x04B",    "0x017",    "0x081",    "0x0E1",    "0x09D",    "0x10C",    "0x1F3",    "0x02B",    "0x1D3",    "0x09C",    "0x1D8",    "0x01D",    "0x0A6",    "0x02D",    "0x179",    "0x0AE",    "0x122",    "0x076",    "0x012",    "0x094",    "0x090",    "0x141",    "0x13D",    "0x104",    "0x062",    "0x0C1",    "0x093",    "0x068",    "0x132",    "0x183",    "0x0B6",    "0x0DD",    "0x0BD",    "0x1FE",    "0x0DD",    "0x07C",    "0x0E6",    "0x105",    "0x1A2",    "0x0F1",    "0x00A",    "0x049",    "0x0AD",    "0x095",    "0x011",    "0x0E0",    "0x17C",    "0x1E3",    "0x1C2",    "0x0A7",    "0x1F8",    "0x12C",    "0x123",    "0x0C1",    "0x050",    "0x176",    "0x057",    "0x102",    "0x155",    "0x13F",    "0x1FD",    "0x1E7",    "0x159",    "0x047",    "0x018",    "0x13D",    "0x1E6",    "0x053",    "0x192"
};

void inputtoneg()
{
        for(int x=0;x<512;x++)
    {
        input_neg[x]="0x0";
        //cout<<input_neg[x]<<endl;
    }
}

void inputtofs()
{
        for(int x=0;x<1024;x++)
    {
        if(x<512)
        {
            input_fs[x]=input_neg[x];
        }

        else if (x>511)
        {
            input_fs[x]=input[x-512];
        }
       // cout<<input_fs[x]<<endl;
    }
}

void inputhextobin()
{
for(int g=0;g<1024;g++)
    {
                
        input_s = input_fs[g];
        stringstream input_ss;
        input_ss << hex << input_s;
        unsigned input_n;
        input_ss >> input_n;
        bitset<16> b_input(input_n);
        input_bin=b_input.to_string();
        //cout<<"input_bin[0]:"<<input_bin[0]<<endl;

        if(input_bin[0]==t[0])
        {
            bitset<40> b_40_1(string("11111111") + input_bin + string("0000000000000000"));
            
            x_input_final=b_40_1;
            //cout<<"b_40_1:"<<b_40_1<<endl;
        }
        else if(input_bin[0]==t[1])
        {
            bitset<40> b_40_0(string("00000000") + input_bin + string("0000000000000000"));
            
            x_input_final=b_40_0;
        }
        
        input_bin_24bit[g]=x_input_final;
        //cout<<"input_bin_24bit[g]:"<<g<<":"<<input_bin_24bit[g]<<endl;

    }
    
}

void rjhextobin()
{
    for(int g=0;g<16;g++)
       {

        rj_s = rj[g];
        stringstream rj_ss;
        rj_ss << hex << rj_s;
        unsigned rj_n;
        rj_ss >> rj_n;
        bitset<8> b_rj(rj_n);
        rj_bin=b_rj.to_string();
        rj_bin_8bit[g]=rj_bin;
       // cout<<"rj_bin_8bit[g]:"<<g<<":"<<rj_bin_8bit[g]<<endl;
        
    }
    
}



void coeffhextobin()
{
    for(int g=0;g<159;g++)
       {

        coeff_s = coeff[g];
        stringstream coeff_ss;
        coeff_ss << hex << coeff_s;
        unsigned coeff_n;
        coeff_ss >> coeff_n;
        bitset<9> b_coeff(coeff_n);
        coeff_bin=b_coeff.to_string();
        coeff_bin_9bit[g]=coeff_bin;
       // cout<<"coeff_bin_9bit[g]:"<<g<<":"<<coeff_bin_9bit[g]<<endl;
        
    }
    
}

long long binary2dec_8bit_coeff(string x)
{
    long long sum=0;
    //cout<<"sum_initial:"<<sum<<endl;
    //cout<<x<<endl;
    //cout<<x[0]<<endl;
    string e="10";
    for(int v=1;v<9;v++)
    {
        if(x[v]==e[0])
        {
            int expo1=8-v;
            //cout<<"expo1:"<<expo1<<endl;
            //cout<<"v:"<<v<<endl;
            sum=sum+pow(2,expo1);
            //cout<<"sum:"<<sum<<endl;
        }
    }
    

    if(x[0]==e[0])
    {
        sum_signed=sum*-1;
    }
    else if (x[0]==e[1])
    {
        sum_signed=sum*1;
    }
    sum_dec=sum;
    //cout<<"sum_signed:"<<sum_signed<<endl;
    return sum_signed;
}

long long binary2dec_8bit_rj(string x)
{
    long long sum=0;
    //cout<<"sum_initial:"<<sum<<endl;
    //cout<<x<<endl;
    //cout<<x[0]<<endl;
    string e="10";
    for(int v=0;v<8;v++)
    {
        if(x[v]==e[0])
        {
            int expo1=7-v;
            //cout<<"expo1:"<<expo1<<endl;
            //cout<<"v:"<<v<<endl;
            sum=sum+pow(2,expo1);
            //cout<<"sum:"<<sum<<endl;
        }
    }
    
    sum_rj=sum;
    return sum_rj;
}

string add(string a,string b)
{
    bitset<40> a_bit(a);
    bitset<40> b_bit(b);
    //cout<<a_bit<<"::"<<b_bit<<endl;
    
    while(b_bit!=carry_comp)
    {
    carry=a_bit & b_bit;
    a_bit=a_bit xor b_bit;
    b_bit=carry<<1;
    }
    add_result=a_bit;
    add_result_str=a_bit.to_string();
    return add_result_str;
}  

int main()

{
    inputtoneg();
    inputtofs();
    inputhextobin();
  

    rjhextobin();
    coeffhextobin();
    
    //Getting the Co-efficients from Binary to Dec

    for(int k=0;k<159;k++)
    {
        binary2dec_8bit_coeff(coeff_bin_9bit[k]);
        //cout<<"sum_signed:"<<sum_signed<<endl;
        coeff_value[k]=sum_signed;
        //cout<<"coeff_value[k]:"<<k<<":"<<coeff_value[k]<<endl;
    }
    
    //Getting the Rj from Binary to Dec
    
    for(int j=0;j<16;j++)
    {
        binary2dec_8bit_rj(rj_bin_8bit[j]);
        rj_value[j]=sum_rj;
        //cout<<"rj_value[j]:"<<j<<":"<<rj_value[j]<<endl;
        //cout<<j<<":"<<rj_bin_8bit[j]<<endl;
    }

    //rj_beg=0;
    //n=3;
    
  for(int n=0;n<512;n++)
  {
      rj_beg=0;

    //cout<<input_bin_24bit_ptr[0]<<endl;


        for(int j=0;j<16;j++)
        {    
            u[j]=zero_uj;
            
            int rj_len=rj_value[j];

            for(int k=rj_beg;k<rj_beg+rj_len;k++)
            {
                coeff_grp_rj[j][k]= coeff_value[k];
                //cout<<"coeff_grp_rj[j][k]"<<j<<":"<<k<<":"<<coeff_grp_rj[j][k]<<endl;
                
                int m= coeff_grp_rj[j][k];
                if(coeff_grp_rj[j][k]>0)
                {
                    //cout<<"Its Positive"<<endl;
                    f_range= n-coeff_grp_rj[j][k];
                    string coeff_pos_uj=u[j].to_string();
                    string coeff_pos_n= input_bin_24bit_ptr[n-coeff_grp_rj[j][k]].to_string();
                    string coeff_pos_add= add(coeff_pos_uj, coeff_pos_n);
                    bitset<40> u_pos_add(coeff_pos_add);
                    u[j]=u_pos_add;
                    //cout<<"u[j]_present::"<<u[j]<<endl;
                }
                else if((coeff_grp_rj[j][k]<0))
                {
                    //cout<<"Its Negative"<<endl;
                    f_range=n+coeff_grp_rj[j][k];
                    if(input_bin_24bit_ptr[n+coeff_grp_rj[j][k]]==zero_uj)
                    {
                    
                    u[j]=u[j];
                    //cout<<"u[j]_present::"<<u[j]<<endl;
                    }
                    else
                    {
                    //cout<<"input_bin_40bit:"<<input_bin_24bit_ptr[n+coeff_grp_rj[j][k]]<<endl;
                    bitset<40> u_coeff_neg(~input_bin_24bit_ptr[n+coeff_grp_rj[j][k]]);
                    string u_coeff_neg_str = u_coeff_neg.to_string();
                    string one_comp_str = one_comp.to_string();
                    string two_comp_add = add(u_coeff_neg_str, one_comp_str);
                    
                    bitset<40> two_comp_add_40bit(two_comp_add);
                    u_coeff_neg = two_comp_add_40bit;
                    //cout<<"u_coeff_neg:"<<u_coeff_neg<<endl;
                    

                    u_coeff_neg= u_coeff_neg xor uj_compensate_neg;
                    //cout<<"u_coeff_neg:"<<u_coeff_neg<<endl;
                    string u_coeff_neg_k =u_coeff_neg.to_string();
                    string coeff_neg_uj=u[j].to_string();
                    //cout<<"coeff_neg_uj:"<<coeff_neg_uj<<"::u_coeff_neg_k:"<<u_coeff_neg_k<<endl;
                    string coeff_neg_add=add(coeff_neg_uj, u_coeff_neg_k);
                    //cout<<"coeff_neg_add:"<<coeff_neg_add<<endl;
                    bitset<40> u_neg_add(coeff_neg_add);
                    u[j]=u_neg_add;
                    //cout<<"u[j]_present::"<<u[j]<<endl;
                    }
                
                }
                
            }
            rj_beg=rj_beg+rj_len;

            u_j_present_str=u[j].to_string();
            u_j_past_str=u[j-1].to_string();
            u_j=add(u_j_present_str, u_j_past_str);
            bitset<40> u_j_f(u_j);
            u[j]=u_j_f;
           // cout<<"adding previous uj shifting:"<<u[j]<<endl;
            //u[j]=u[j] xor u[j-1];
            //u_j=u[j].to_string();
            
            if(u_j[0]==t[0])
            {
            u[j]=u[j]>>1;
            u[j]=u[j] | one_uj;
            }
            
            else if(u_j[0]==t[1])
            {
                u[j]=u[j]>>1;
            }

            //cout<<"uj after shifting:"<<u[j]<<endl;
            final_result[n]=u[j];
            //std::cout<<std::hex<<"u[j]_hex:"<<u[j]<<endl;
            //cout << hex <<"0x"<< u[j].to_ulong() << endl;

            //
        }
        
        cout<<hex<<"Y("<<n<<"): 0x"<<final_result[n].to_ulong()<<endl;
  }
}