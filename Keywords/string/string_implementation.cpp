
/* implementation of custom string class 
ref: https://codereview.stackexchange.com/questions/98329/stdstring-implementation
*/

#define INITIAL_SIZE 15

class string
{
    char *pcString;
    int iCapacity;
    const static int npos = -1;
public:
    /*defualt constructor*/
    string(void){
        pcString = new char[INITIAL_SIZE];
        memset(pcString, 0, INITIAL_SIZE);
        iCapacity = INITIAL_SIZE;
    }
    string(int iSize){
        pcString = new char[iSize];
        memset(pcString, 0, iSize);
        iCapacity = iSize;
    }
    string(const char* pcValue){
        if(pcValue)
        {
            int iSize = strlen(pcValue) + 1;
            pcString = new char[iSize];
            memset(pcString, 0, iSize);
            iCapacity = iSize;
            memcpy(pcString, pcValue, strlen(pcValue));
        }
    }
    /*copy constructor */
    string(const string &strInstance){
        if(strInstance.empty() == false)
        {
            this->pcString = new char[strInstance.size() + 1];
            this->iCapacity = strInstance.size() + 1;
            memset(this->pcString, 0, this->iCapacity);
            memcpy(this->pcString, strInstance.data(), this->iCapacity);
        }
    }

    string& string::operator=(const string &strInstance);
    string& string::operator+(const string &strInstance);


    int find(const char* pcInputString){
        char *pcSubstrResult = strstr(this->pcString, pcInputString);
        if(pcSubstrResult)
        {
            return (this->size() - strlen(pcSubstrResult));
        }
        else
        {
            return string::npos;
        }
    }
    bool empty() const{
        if(this->pcString)
        {
            if(memcmp(this->pcString, "", strlen(this->pcString)) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    int size() const{
        if(this->pcString)
        {
            return strlen(this->pcString);
        }
        else
        {
            return 0;
        }
    }
    char* data() const{
        if(this->pcString)
        {
            return this->pcString;
        }
        else
        {
            return NULL;
        }
    }

    ~string(void){
    delete this->pcString;
    }
};


/* '=' operator */
string& string::operator=(const string &strInstance)
{
    if(strInstance.empty() == false)
    {        
        this->iCapacity = strInstance.size() + 1;
        delete this->pcString;
        this->pcString = new char[this->iCapacity];
        memset(this->pcString, 0, this->iCapacity);
        memcpy(this->pcString, strInstance.data(), this->iCapacity - 1);        
    }
    return *this;
}

/* '+' operator */
string& string::operator+(const string &strInstance)
{
    int iNewSize = strInstance.size() + this->size() + 1;
    char *pcTemp = new char[iNewSize];
    _snprintf(pcTemp, iNewSize, "%s%s", this->data(), strInstance.data());
    string *pStrResult = new string(pcTemp);
    return *pStrResult;
}


int main()
{

    string s;


    return 0;
}