//
// Created by douxl on 19-5-22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> pow, pow2;
    long long p = 1000007, p2 = 1000009, mod = 1000000007;

    /*
    Rolling hash algorithm:
    Let's say we have a string abcde and want a hash of length 4 with prime p .
    The initial hash will be in form of a*p^3 + b*p^2 + c*p^1 + d*p^0.

    When we want to shift the hash, we need to do 2 steps:
    1. Remove a.p^3: // hash -= S[pos-hashLength] * p^(hashLength-1)
    2. Shift the hash so it become b*p^3 + c*p^2 + d*p^1 // hash *= p
    3. Append the new character. // hash += S[pos]

    By doing this the new hash will be in form of b*p^3 + c*p^2 + d*p^1 + e*p^0.
    */
    void modifyHash(pair<long long, long long> &hash, int hashLength, char current, bool rollHash, char toRemove) {
            if (rollHash) {
                    hash.first = (hash.first - (toRemove * pow[hashLength - 1]) % mod + mod) % mod;
                    hash.second = (hash.second - (toRemove * pow2[hashLength - 1]) % mod + mod) % mod;
            }
            hash.first = (hash.first * p + current) % mod;
            hash.second = (hash.second * p2 + current) % mod;
    }

    void precompute() {
            // Precompute p^x and p2^x to be used when we want to roll the hash.
            if (pow.size() == 0) {
                    pow.resize(100001);
                    pow2.resize(100001);
                    pow[0] = pow2[0] = 1;
                    for (int i = 1; i <= 100000; i++) {
                            pow[i] = (pow[i - 1] * p) % mod;
                            pow2[i] = (pow2[i - 1] * p2) % mod;
                    }
            }
    }

    string longestDupSubstring(string S) {
            precompute();
            // Length of the answer and start index.
            int lengthAnswer = 0, start = -1;
            // Binary search left right initial position.
            int l = 1, r = S.size();
            // Set to find if hash has been inserted before.
            set<pair<long long, long long>> st;
            // Pair of hashes used to reduce collision that might happen if we only use one hash.
            pair<long long, long long> hash = {0, 0};

            while (l <= r) {
                    // Hash length.
                    int mid = (l + r) / 2;
                    bool duplicate = false;

                    st.clear();
                    hash.first = hash.second = 0;
                    // Initialize the initial hash
                    for (int i = 0; i < mid; i++)
                            modifyHash(hash, mid, S[i], false, NULL);
                    st.insert(hash);

                    int pos = mid;
                    while (pos < S.size()) {
                            modifyHash(hash, mid, S[pos], true, S[pos - mid]);
                            pos++;
                            // Check duplicate
                            if (st.find(hash) != st.end()) {
                                    duplicate = true;
                                    start = pos - mid;
                                    break;
                            }
                            st.insert(hash);
                    }
                    if (duplicate) {
                            lengthAnswer = mid;
                            l = mid + 1;
                    } else r = mid - 1;
            }
            if (start == -1) return "";
            // Construct answer
            string answer;
            for (int i = 0; i < lengthAnswer; i++) answer += S[start + i];
            return answer;
    }
};

class Solution2 {
public:
    typedef long long ll;
    typedef pair<ll, ll> dhash;
    ll p = 1000007, p2 = 1000009, mod = 1000000007;

    dhash calhash(string s) {
            ll h = 0, h2 = 0;
            const char *str = s.c_str();
            int len = s.size();
            for (int i = 0; i < len; i++) {
                    h = ((h * p) + str[i]) % mod;
                    h2 = ((h2 * p2) + str[i]) % mod;
            }
            return make_pair(h, h2);
    }

    string longestDupSubstring(string S) {
            set<dhash> st;
            int l = 0, r = S.size() - 1;
            int str_start=-1,str_len=0;
            while (l <= r) {
                    st.clear();
                    int mid = (l + r) / 2;
                    bool found=false;

                    for(int i=0;i<S.size()-mid+1;i++){
                            dhash cur=calhash(S.substr(i,mid));
                            if(st.find(cur)==st.end()){
                                    st.insert(cur);
                            }
                            else{
                                    if(mid>str_len) {
                                            str_start = i;
                                            str_len = mid;
                                    }
                                    found=true;
                                    break;
                            }
                    }

                    if(found){
                            l=mid+1;
                    }else{
                            r=mid-1;
                    }
            }
            if(str_start==-1){
                    return "";
            }
            return S.substr(str_start,str_len);
    }
};

class Solution3{
    const int P=1e7+19;
    const int mod=1e9+7;
    const int maxn=1e5+10;
    long long powP[int(1e5+10)];
    long long H[int(1e5+10)];

    public:
        void init(int len)
        {
                powP[0]=1;
                for(int i=1;i<=len;i++)
                        powP[i]=(powP[i-1]*P)%mod;
        }
        void calH(string S)
        {
                H[0]=S[0];
                for(int i=1;i<S.length();i++)
                        H[i]=(H[i-1]*P+S[i])%mod;
        }
        int calsubH(int i,int j)
        {
                if(i==0) return H[j];
                else return ((H[j]-H[i-1]*powP[j-i+1])%mod+mod)%mod;
        }
        int judge(int len,string S)
        {
                set<int> pr;
                for(int i=0;i+len-1<S.length();i++)
                {
                        int j=i+len-1;
                        int hashvalue=calsubH(i,j);
                        if(pr.find(hashvalue)!=pr.end())
                        {
                                return i;
                        }
                        pr.insert(hashvalue);
                }
                return -1;
        }
        string binarysearch(int len,string S)
        {
                int l=1,r=len;
                int longestlen=0,start=-1;
                while(l<=r)
                {
                        int mid=(l+r)/2;
                        int temp=judge(mid,S);
                        if(temp==-1) r=mid-1;
                        else
                        {
                                start=temp;
                                longestlen=mid;
                                l=mid+1;
                        }
                }
                if(start==-1) return "";
                else return S.substr(start,longestlen);
        }
        string longestDupSubstring(string S) {
                int len=S.length();
                init(len);
                calH(S);
                string res;
                res=binarysearch(len,S);
                return res;
        }
};

int main() {
        Solution3 s;
        cout << s.longestDupSubstring("iuiielmwbuhncfgvnsnwwcnzgbuylftyoopqrmkbycbubrvrfvwbufeooizjydgtpuxwpauqklqqlflzizazpevkcqysqyxhxpksvhnwdfaxqbpokvropwipxjfxcohnxvkyxybgzprkpsxmwuzdgfpaimcprhvmmqvijkfyrznhoucelkyoogemciorlzwigbvehltglnxirtedwhcxonzvbevluqpdcmmbxbdxdcfwdsnbcqbtuindgtwfnoadpchnzgkaeyjaonaehuyscbgnmuedyligijyeretyfubaazkrsexdbmxdhgquyvcuxyhfufejbwfcgurzireoprfceghntuvecrkfolanunkhigeqflufocnxjvfixgkjnbvoxwizvbelwhcdugmtohuobyrjesztnglsykfsxnikagckszybiuywwsdzomvaukufdcaeamdlblfixrflpqybajdnyrbasqegunwnpjejvpcsonfhqdzmhewdbqcdsjpcsvhmdprqujbsapfkzwwikfcdzhndnelhvnqilrtwbnzytsrmfpevqrupkdxliohtzbunzeyqskrvasycpzjrcwzywtqnoljzzkiarptcixcewpdqrcczchabvlnwtnrqxsvygrbpncfenkgojvomyrkqcxjzmxpsdofriwyljtwpibhfkvkkrnnfpbvceqrrustnplvogqyjmkjadalslxogdtuupzmdgkcjridzmpcldmgxrolnebxaodyshachjanskuwnsljumqrudjrjipequhqwxgpwhgnigdemdjsawvukqlamxxzqiavunzpkpuogpoegdhvxiedzvmhbxgqlhhwjlqexbojjnnhogktvedekmynvuzonqwwyntacpawlwtxsajrkzcivhnaukxzgugwdirrgwofasmdhduyaakqclvzltrdlwhimpvmwgeebvxfniupaxpkaqnlzpesurityfslpbdtffbqipbmkxfarpgteuwoaabyoqpkwmpvyarqzrbidzdcqkiwsgimtgllkjrgbzzmkogqsmpoglbqanilcqumpqotffhdymbjuftjwkljnyqpxzqffbncifmemtkxayaxzslfatiwnrtjdiyknzxecwrabvtoypcsaesmuvqgvkrykynxwzhyuurykveahbehtplvuzjxncegdfjpjlglfzwpipehksjswqiawipwdugltppqbujjopitgrtpslxpsfaanccsqtyuypztsplpfxxogycjpwmckdugknbcbbtjyqltlhtmtpdolptlrhaxnzchtlohcvgehkhlbewdcqswogzbjjzhlkheyamljyudwrfiqvfgekbtzyulwadkgdpflfxvpshcmlvrzzdgkdelodppwjyljmedrmhsfozmtciduaebpjaagykojwlrxrxqdsjvohrjzneqbfnsnkjxiguyuprrqzbaxpdrurgzhwmfylkmuxouasuztymcyzllvbcrxfjmwhcxdbgdzdzevftxabzwsisdwpvjauaqarkjwhjciqxckfmeqdhuvjljtrsieqkltqxgojmiqmnkxiedqowhnsrfwlcfdmwglidgcgvpjnfnqncusbfcdqhbrxqhslpxxynudulzfvvachayogeasyalhmwbknrkynwfhriqvhzykdsahlpfeoppkecxaxltkkygknvqrdpaikbzzlusnslcqxqojojytpagkfbiyezpbyfjgixqyzcqygcvwqokurblqyzqryfjdeeflqgworjltrfpkmtzafvuhdoqizyhqtzbpbvlziczhkqxcbdbxfiwsihytabcujqgyguxkaegmrnrasnolyqorspbmyanndarkhlxcpzxrznuqlligznfuivhmkmfdesyeuwelnoikbzhwnaltruclcchnximwibwtwjdnqofvlvplvkireoxorwqlcytwiiajbalhawevxwdefkvaezhfssbkytzrjwkurxvcxhhblgfcyhoubsnzlsvganxijgecztbklughbtulvwwkiizcjtadhmkbrdrqjcyfmmilriznqrmywjtzzzlsrgfhgoqldvdirohuqznwatmcoygzopqbcwgnsgdrygpichbxjzxsorzzkhuaexziyccrgavgicrazujbsgsloufonaydhligxlatxvcinnjkncsvngsadpghwxvzfgmanhvkvwhenvsedpqyqnqvutfydppubsjsgbqrbruhpsrrpcsmyndrcskkgibkvbvelljogfezszbgcjoppnqhzmuvnjvwtmkggmfiqwwbnnpylbqdxtmfsdwsogyvsqwvpczmcvahqqwtzykytirguxjcqsgrplqytzaojsuxycovdtfyxwimxbgvzzvmpitdxbhkegdocgapbrfrvjsormzjswoxdrbsurorqqrquhzorxmypygfvjdwbxndpzveqzoiflewwhmygwifmbpgfvkfmaiodfwjmgejlwgytdjhczbcivwsppuqenunwyyxtcrhxonwywpgpqcujzlflplxbocbpmoivakwsevzxggatdzqeztxrkkyjaugjexinqedxtkwykgbnyumjkrosrllqrryhanlwegnfordfexagdbafjstqlzoluqaxquhduyqwmeeimmgdraosatsjgrwygcrqtweieafsubczzxhixrrcxmiwkqjjtgzhblszwiwqjnxoprxsycqvwckaczjfxbrgaoxfujnqqpwehgtucczrdqctaibmccokvxdyqpxmfnnlbzwkmpgfjhcusqnkipkodkpoobbgrsokfjsyqtcknepyevfsdtdidrjztugtlcqzjgupttcktbslevosvbgxmxrbsvkuchcgxpdthtmuippirutisdiwiomubzdqosqdsnnszgatbnhovpizmbbjgxvgbxiryresmfcbswsgcacimyzjpwmxsdigibckikxeuixbbzvnwljhpxzwrcettnzfdsosvfrkcaxghlqgbsnlucvyfkbpmuniqdypguiaqswxrrzfhoeogjpwzztseqmoaksqgdtgcswoqbcrvwztprnsodzlrywzlgcsgwxeloiyvsstrhityqeukvocgoytrjbrusiovgxqdshesupvpecziigkuyjuwqpagfovhaeurvdegwtkphppinfacgngghiqflknmvfdycwqbqxerhguqnwzjxsfbwwqbjinqvgsmbgldgqwkokzqlwdyzhtdqccwtydtpqewkatinmpdolyosdacsmpujeyfwrhvqihorbgasfzpujvcsymigqlqynuotsomrlwxywaspgqzkbfckyipzxjrjrbkqluwefgjjkpkrurwypmsvxmyqnyqonplfwnjgynrkjodvmazdjyiqiwetdzjyaybpgjlddkncljpqgtpkgoavbbwbbbndobbcbaktvwrxbxulmknlzwgdocnngwmkezhdcnbkyjgtbubvtbntwqourytmldlxmbxxrndximtddesbguqyzdwykifnsbchkxwlsewcisrcseipfjohzrvjxqdqbkafzahqiwjbzpbwdayygweaoovabtiqinibadluqvgzxkuiqgulcdemfgltvaqbwtuyoqxwqdurhydunyqniitegfcrknwvubclfmhqyvtnwmuoypwzchjopoguwythwrmbtymcnxqvyojlirkvlzmebmscjuwgqhkfqnwcxhrnhprfaamqiwrplvdmxdfqfiysqpwctuqmggopuzqbxartbjlutpycbgsfrtljhwftutnaawqruozfxuqjqomschcagdxxpgwejrotntqlgvsrmsurxigmxpiuretciynfcbejaqtpyjlbgilvepqndybefvhcdiujubrwhikmodthnbxixlunuwqgribmodtyxouhyafdlqeskmeuoyhakttlvpyqxzydrhwgrtflsvmvsvtidugaaybvuerlrgbxjkshxtiplxsyhcnncrchkeumqjhusubuwaketwqpmowjvfwuuzrrpgekxmhkglmniocmziucaqvirppcjucqedfnjfyaemvxzwuzzyeziwbvalguyezjilqekqbqhkgbgjaoilrfstvlvmoeenlicatngpvrtuuywqpeemnnvgtevkxznicfjwdbgclxaenbchgqnvomhkaafbikujrbnjqfzvgopcnlujejmcmdvbtxrlrkyqtayhgkdyrieyuymnofwvzycidrhduqlmbpuaztkmkqxlttvibhjwdgoaljxlxcjiitkjyemveqhyjvgfnprceuijcfxrctjjtijwzwxbxmdsskocxtdyvqsfjdlafcgpbwijdirvsujfezbfewtwafmnrdvqegivxmyhcttkbwjffqphjcoackbprrcbxevwqwipqcqzdjuwpbrxymzibmuriqabwtsisijildsuvmsdlteywhysfavlpyptjhccnkiugzzxurqcepuvhddjdnpbidexqfbzkskmxqfcfxzdqhxywegnlevxgzkfwyyebkypfamodeshsispcbegwbjjbalcdpuviysvppknfhawynczychthbojmyjiihputdlnrnwgsgiejddxfpnayfajtugctqnkfrjarbkzrqrvtlsgnqqmvwtpluzwtthkiomnnfdjvuqajkarcvkpwtvzjariilatklnshsqdhtiejulcvgrtxqodsgoimpcyypsnxppjhkxrnstowomqqgmosisopgwnjaypvmtuibypfuduvnjqxamllbadgejvqroazkpbqzvkrcsmjnmkkftcarhqaqfzuaqwlixhemwglmejukgthqjocckbrbmhqucrenfqoekrroekxafvlzutdsscvcbitjuztwkblfyaxirptulfvrmmthijxwlzuytxoupzvvmkvdvntiawdfhattosqhasuikocyqywjohfqgvbsajuqfwwzxywkxsntrggwxffzlxzhlvhyjiuvhxplnrqlpqudoleljxcntsjsngmyehrwwruvwexkyqbbhlvwdojprakqahdunowuyaoqmnrzabxqbkfwlzdfxaebsufrogtoldnryibgggigtfmfyjdynxwmwirrnufbwpkgdqhohuhozzikjyngireqnypatlqscdreveyzrpwolcpzmxopwqpfejtutfeqaczjtzguqvznkwtsztgfimbazhixrvtyowlvhokmfgxlrfihxaucezqlkupcccdyysydzwoftbkxelotvlnquwqwkoxxiauntglfuocepewopxdeadkcghdscqmejdwgijdcejervtsiwndjqjhccotkbatjgxyxfkzbyyuqtjvfqjmevhjmxomaxwiapcwzatorslgagjtykmwegrbboritytawndfrymzjmqawlwytseugxhyyijxofallvshguvdxuzaqmzzoqrwodkkrsdhwhkgemsktxsrokcablkybfqbllulxqpkkwswmrxnznmtknfdqarvgvltojfismrvfcowmtrkdcqilucjslnxdwyzayoxejmhjeonzwdqpjjovumpkibgcmotazussvaofxnuladaghokxjntfqsdybvbwcyhusfdwbpivpvuxxfwbcdyvejkfzvnbbrohbswnhcwfhhylnsnayzglbirrdjksrxyeyftxmuhagnufhzyhaniersbdtjdsrlbzpkoyeehsgmerfqgnltzvywoeldjidhjsakcnjbvgwdaocxxvgyjjkigkrnpvwkzynbpziatncmmlharpqwqekvokamjiuptfirqhijulebypdwriwlwdjilenpvjpusftctulbqgduqhfbmgvylsmzmpczxlbdqkhdeeexiyxpdfpzynltvnptyfgyapooqcbgluqvgdopoyrhhbdmogybhljnfhcrehetpszeaohtbvdamtloaxrpgopxyennxavrsabnxdxstjyhcdvzhfgozitgiennalbgrefilibegrfqedmniyhhvttczrkgmuwiasqykoazxpxmczniyjnopyqtvvrquztexhmqztarekcunryrvptokmaftaksdqeejtdwnyplgbmencrcygdmenxxzdstwcbccxatpijavxxnxyflpnneeagysquecbjrvyoogborlxrybpydsvkffseqyeevcxontmqkmlpgqsymwpquizbawjpqpowyomficyahanqdazfvnaczfcfgoedtttdfaazknxycqynstwixfsdushmxmtjqwcuktjmcnyzsncpblmcnbnhjbxonazdpsrvyjcuxymenbsjpacgveuwsmikyieyoavdyejrwygyuhrvjwuydvfcjxxrvuwkncpfqucitxnlpzzxdudlxdgezetdsealhrmllajnznfnlanobgjxoxsdwfcslpeqmvjnxgecvynvkwiofzmfnqkthbxlfawyughefssnzcoaiwinrbqmztkgkcuzvsmxsvudsvdsfknyzhdastxikmhfrvfumteremzkfevrfdvjsebmyzivtexdhsjrrmwjeevktcmlbtsweygbnydwrvzoynzlcfbbhqacqqakubzgwstxenfiggdwsrnkkvfnbayeuzwulzdhmrgpxktnvleqvsdakkncojammomwgjnkoalrzzaijnpsonjeipgxxcglvosgasyifkoymqvhlzsqrhonohhsqxjaqswocmmzlftxebazvojjaijthbavdcutwekqboqvufpjdmcbphvjovexrdyzwefwzzlazqhbubmjlduzfvytpdxkkxhycynysxzomqsomfcaxaxtqbnabwbycgdeqwtmclkzuyyuzqhpjhwismgutwmrvlsbtmirbjivcyjmchlvyflxvdjdjjuevofvxchvqcnifakvnmvpqdzusxklvzfwihejnhxqofbmoisblanxdftqerkxcrgfanwsqnnhpjqwhequlvjesmymayqwomhajjpzktfbbqdvrnfzherypszsmxyixkfihwfpjfsljaifzzyfsoxpikgewuinlwrvgohgfqxxryrxfvxkhgtcpqcbgeymlfydkudegopfgnpjkrzsbloevpdyxbmhtbunpiiwfjpyoqojlepyqaajqjbhnqlsnvcwdryulrhijiwmlimbsafhcucyhzhgipiahnzkwiysutzxqkxepddfckgmrdiogjsftnvpzuhhatpckrodafgvkvkcqzaozbqkdsfzzpdxfbqtcjgejxftphontqnsoeeiezewjdfzuuozavgkspsozmrvkhebfunmdlecdojzczqyyyzcyztdvykmoxveqexkrxzrnqeyjmuaxaapsosqczbzybwnqetmmybnzlnsmygyxbupbolxbudxvazsdtkrbbuvylxwiyqviwtafgbfefkjdrocnfxwhhntmfrrexetmkadfduahzqdnpujcxfrokgvhjthjnbwbherwawknaxvmfrflraapevvmqodvgbsihtucirswpheqjxzpfldjioezonporgokkgiaszhcudfeecvrddieorjmufxftcztnxafnlxkmvctyetbplblybieolafdnztmrhcgzmkeqpfmbjbuobtjaodjpdvaeomoknrappaibtrqezxamrifufzowfkwdjepalxujaogrfgxnxsskkxfnhtfvgwdrrimsumxzcqqftsqywpjhqhudnxsxynuxqgzcwpcltluzymkbefbsvrzjwrnljaceisidppyhjqaydxaslioetbjtanggbhqkdnhzsgzqbtspkmteoymvxsnpdsaxsgmkgzidqcwcesmhjpkvppzmsdgjcremrvbmkllchrlrylcjrvclszbmjihppjckszfobbcqqpxgtcphndampzwcyubpuapgitlivdhcmkoeuyecrbpiofqnrodlaxwuyendreinfkhvnadnkiqhzpdbisymulfhgoyvzvvafxzonnlplkiywodfflqccmlldipxztimfzpvczqrmggfjguayqqvuwcerpffijttmggfkgnnhbweosrzenmkmhvzizrxrwhkwarquiqcjcbcpiyhyvddfvqpsxyoipaufjfxosuslehiwisberbuabcufajdhyheaghjznvbphmegnnikmtpxgxlbkxstvrdyvmuysnnmgrjbdiixknockznluhczbgsqwtsxfmcfbohncdwwhnfkiadefzffsbqaihgukavwdhebcwzuvqcsdwaubwwpddlioysxrlcdpzvwhfpnncuesxxftujqykgtuvejgnqnnrgusurlltpcjncxggbcpmwonoeloemjugangzxhzafkckiwjixvtbvkqeuxcouzlhqepencswgdljewlzrmmlktatczgknvpjdtjrdyvrsorkrgwvxgeshncmwjcmbqsbckkedxnxcxeoqnufgdbiltqklmepsbvdxqyxosrxgyghohoherenqqkcdpshcgnvdsiaqgbxoiwbnstulorlkqtoyofbdiwqqyovaxlxwqoxaukjbdwpcvgooibvkojcgkmopqugackzatnfmfcdaksnnzcabghdjlpqgslkrinljntnyuxesiiasvfvpnsagrtfkhxizebjffnynslylxqhrvcgrbhpplbadttmqdymdurzieqekizqkzhmsilrtnbeotnwwyltbkiahdderkiedspilycjvjfdmggvfvswcddpqtdaozpwfycsefpqicbusqdhucbndyttaypybxwdepqcgpfnvljkbocqnvsewciqewxxpbwbhawputrnkkqtpbcdytidiebeykrppuzrhycmhgzhknfjdzkpfhoxrswedhnvnyxdtxedukjirboigwexslnbtisyfbiurqkiitlclrbjleborreizutjsnsjvcpcyhuginhnnhanxjsdnjbmtwbesuecdhdemtjskvitfqmhhgtflehrafopgpakeswseinhgfpgaavosthlbffwgmkguoyyrjeyhtkgsegrbmubhfimernxhlhcdoqdmyhuxzkkyjruehkqocfqzobczljhcucvbzbivyaihegmabccfbkmkaoezugliicoiyrfsqdzhhwhxynpjxjsnkbpvytyejoctzqfjafwpfnprtnhkwknnrikpylswgszrgeffvroervyofynycbzgrgcdpanrfeyqbxgngzkbhdagzfhnpnvluakfdhfcvogyuraankndrbruhkzhmxzbhmvhmtakmsoozuawedlmjhhuvbmeyhdnhtacddcgsfuadhboinhzwmknyyvajtrzhwfwqlvehnjxckdjsybwhsoatyjklznwxwslmhzrdaxowfghfiolupjbmkdimdxwjobbrnuyendnsbahjtkbxgddzlkkdaflakikvcwivzhmrgpfckymwtnwlzrlnthfliwpdcpwtloajgyjpdgleudwpnouiojbepkmgvgkelhzcyutnsapuqkamwkpiextoytjiwtpkbdkqgltwsfaunkzogrbckhxiabwrvpmwrpoyuwgalbkgxifluysrduuzqbtemnmfcegploawzsibbqnyjwlflsdwwrnlszgmypbnhrqxcyiwlkkqfvqumeywjssnhgetejzukgztzrmvfajyraawogpozyuarxhcurnzxdsbnyckplrkkxwwcjipbwfqbwtapyhlwlowxdebbkpimustujkxyqhgxzuiaddubuxyvosfkplgimcpkosyyabyzyuyjxzohhctwelxtemvfsvgdmyktvvxzhftjvxhwcayhudrsgjmbhbxnecydibyeegpjzgicteyylbzjknqhohbmjqziupajbtiiugytyxduzimyspucowurhjujqxodbboknjnynmosftdtaxqfyteimcelkbryjnzmznpnshcegempkyyldtzlnpwbcypnphlnwtxmvlhbnjxmbbockwghzszbpgmhsiebxtwmndnyiaoqzdhgfzuakykqmxmksiqtqusbsbpntnwevrckjarabrhncjrqytncwvfxdfmntuoabminszlpjotflublgqmsubxbskevjzsdamfmlmzoscrmqnufjermnvlzlkbbipehuenispznvzpilcjrtflretqtrgwgtsdadbyfidxowihvdvqiidhzzmmqmzgjiedflvgtlscaumeskqjaoczhaopsndkcpleygaxbmglxxyhphrbypbroaxntjzuovpmtahmuxnynafjizuknpjwwtdrvqbmqlvpaxgtvjjpbxygwhawcokxqlderwdrtgvtnhkbvpzhjiqoccvrtwwwfbxsdttudydynaupqujupxtiaxpvgfremzrbzdbcxqjchkmpzpzrqomrfnhslboovebwqyqdmqppvxdkzppzcrypsxwdftquwwbkokyjserfjcprcrjdvcscgmauarjajrkrerszolcwxlkufnuuwbgbmhyzqsnhbkrpqdxirveddvphjaaxrcpfepexwoxwuxkjczkcfqfqyghregbciujqtqoiwyjfggmngsohbzgpcpwsfubvibqzblriuyddykexycnkmbmfzubbdyaqvgclvgngrlodpeayjuiwcfvfggnrifgzbfuywuhdlqiluddrxdmrsuojrulcttiwshoekpgyqxijiwlyjjsypqllcgizpxkhyghkogksxauylbntfdfgotoncafqwxsjyblhdujzmtbtqlkzrxpjpqsglguydkoghjwroocjjesulunomntrltllpeiqtnsghcbnfdvcwfrzvlmxanktjezkzksewpvbaikyvaakygdnrxgsfjnwzkodpabijhxugtgololojikptabzdbbqolexhlgljicwpvvbhaegjacahfldtfgsfizlyyvydzmjskemupxolalwnmygzrtzcprngffhndlocuksjebdbbtlphwpljhpiwjxdjptsljvjvnleigmkotssxspuzlgmqvdkwazpzbolpkushgrwhjovhmkuxqzmdtcbbhtomjyqbwugodehtoofayipuvxzvtfwitxmyfisuydmtxxpadqwxuvgetkyjccrcqmomkqhmljtnxpsizoblkkzgscxeudbdftmmhysgkngorlrxvrjbpyaubslahfmjjopzitkwtennnvkmfbvkvzcfhdbhvwmwkxmhgdbevqdudgqjczffulfnqqvakqqycjvrdqzvzpzerahrhkbzkitbzdmzruspqrtbzpatyoadrblojebbbrdsxgtedjqtiizijvjhjgfqqqltbornlvdkhslkujnoxgsfzwatwmeyslbmvayyhexjqihfpwjywfudkqxnusvyzlngenlgvtfldfzqsnqtrnoxzmlrmmzhiejvtzyyvefspdvbefdvxczuroqrphvdggavvvymkzhceauvlughgofjrcknkwcolosyjoxljvzjrhtaamblyslwrpzzwnwbuolpbewokwmarfnrwshmeyeeyqmuvnwyhhmwagigwttijiphcusidtefsroouppraododegmnuxxkgpzhikktosefauwmkllaloltkfbndfycmzmhvayxpbhpqiuillubqkkfxrkfhuqqhijfkxvwsztpvlbhrgzwpfjnceqlvrddjyfjjicfobupseddhpqerjugaluujzmclrnjmyfveujgprzhykwtllvovrphlxfywtkvvaixwostikokmydrbvmjpzqaybwbgvmlfdzpzuczccsbdooflhpjksrhqbdclmquraewubcpyswzfwwtelaweqttmmiasfkebfdlttjpulvcvekzwgntroogeaxeskdplmebafuagqjbmpxbrikmsrjamwkdhufpohctgsqytayrvhwtcpewjbodxcxpwkrqoemvmtwxrksxbimxwquwhhofciohgqtxxuqkcojaugnyhuzkttkjhsvupifkvhownbfrxcqlfeioglfihprxnmvpekepjigzwfhdsexhpjuafrbldmxlcrjssvjzpzmaclxvdwvneplkkvbxpqndqgbtvacgqnxzavxssjmjunwseilskdfnvtzmljplmjemgecumxttmfaswqclptipxbaljmfwjvoymsmwgzewadhycyycppseourdsfalacwbatfhgfceesctmekvtpdkqqgswijasdzfzwbjxzjtskvhlvbyimfzqukqrkzjyrnsaryeytttcnslkgsrtycibxdzgtorgajqfwibriticzfywlljfxyyufoffsdmaufgrfrawtdqserkjjemdgbvldyaothljxkeyutocfbdyfochjoxldlzyoefyskvcyvyuywqeskimbtitmovswieboyimigtcbuqgwasuvpxakweolyjfxqzxqntmlxypqesinhbspaekwdncciydxkbtvkqczdaxsvdnbkznwhirflizzbkekeemoghlizqhabxaifksirajlgryjkmqetumgbvvgarothabinftqkywrhdelgabkxopbjurwqtsoamapqpfeslprcxbmpszglupdlwwjofvxjvrrrsfqwjvztymtejxgdfg");
        return 0;
}
