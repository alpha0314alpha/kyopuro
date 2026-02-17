template<ll mod> class modint{
public:
    ll value;

    modint(ll v = 0){
        value = v%mod;
        if (value < 0) value += mod;
    }

    modint operator + (const modint& other) const{
        ll res = value+other.value;
        if (res >= mod) res -= mod;
        return modint(res);
    }
    
    modint operator - (const modint& other) const{
        ll res = value-other.value;
        if (res < 0) res += mod;
        return modint(res);
    }

    modint operator * (const modint& other) const{
        return modint(value*other.value%mod);
    }

    modint& operator += (const modint& other){
        value += other.value;
        if (value >= mod) value -= mod;
        return *this;
    }

    modint& operator ++ (){
        value += 1;
        if (value >= mod) value -= mod;
        return *this;
    }

    modint operator ++ (int){
        modint tmp = *this;
        ++(*this);
        return tmp;
    }

    modint& operator -= (const modint& other){
        value -= other.value;
        if (value < 0) value += mod;
        return *this;
    }

    modint operator -- (){
        value -= 1;
        if (value < 0) value += mod;
        return *this;
    }

    modint& operator -- (int){
        modint tmp = *this;
        --(*this);
        return tmp;
    }
    
    modint& operator *= (const modint& other){
        value = value*other.value%mod;
        return *this;
    }

    modint pow(ll n) const{
        modint res(1), x(value);
        while (n > 0){
            if (n&1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    modint inv() const{
        return pow(mod-2);
    }

    modint operator / (const modint& other) const{
        return *this*other.inv();
    }

    modint& operator /= (const modint& other){
        *this *= other.inv();
        return *this;
    }

    friend ostream& operator << (ostream& os, const modint& m){
        return os << m.value;
    }

    friend istream& operator >> (istream& is, modint& m){
        ll x;
        is >> x;
        m = modint(x);
        return is;
    }

    bool operator == (const modint& other) const { return value == other.value; }
    bool operator != (const modint& other) const { return value != other.value; }

    modint operator + (ll other) const { return *this+modint(other); }
    modint operator - (ll other) const { return *this-modint(other); }
    modint operator - () const { return modint(mod-value); }
    modint operator * (ll other) const { return *this*modint(other); }
    modint operator / (ll other) const { return *this/modint(other); }
};
template<ll mod> modint<mod> operator + (ll a, const modint<mod>& b){
    return modint<mod>(a)+b;
}
template<ll mod> modint<mod> operator - (ll a, const modint<mod>& b){
    return modint<mod>(a)-b;
}
template<ll mod> modint<mod> operator * (ll a, const modint<mod>& b){
    return modint<mod>(a)*b;
}
template<ll mod> modint<mod> operator / (ll a, const modint<mod>& b){
    return modint<mod>(a)/b;
}