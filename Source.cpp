class Polynomial {
public:
    Polynomial(int capacity = 10); // 建構式
    ~Polynomial();                 // 解構式

    Polynomial Add(const Polynomial& poly) const; // 加法
    Polynomial Mult(const Polynomial& poly) const; // 乘法
    float Eval(float x) const;                     // 評估多項式

    friend ostream& operator<<(ostream& os, const Polynomial& poly); // 輸出運算子
    friend istream& operator>>(istream& is, Polynomial& poly);       // 輸入運算子

private:
    Term* termArray; // 非零項的陣列
    int capacity;    // 陣列容量
    int terms;       // 非零項數量
    void Expand();   // 動態擴展陣列
};

// 核心加法函數
Polynomial Polynomial::Add(const Polynomial& poly) const {
    Polynomial result(capacity + poly.capacity); // 預留空間
    int i = 0, j = 0;
    while (i < terms && j < poly.terms) {
        if (termArray[i].exp == poly.termArray[j].exp) {
            result.termArray[result.terms].coef = termArray[i].coef + poly.termArray[j].coef;
            result.termArray[result.terms].exp = termArray[i].exp;
            result.terms++;
            i++;
            j++;
        }
        else if (termArray[i].exp > poly.termArray[j].exp) {
            result.termArray[result.terms++] = termArray[i++];
        }
        else {
            result.termArray[result.terms++] = poly.termArray[j++];
        }
    }
    // 合併剩餘項
    while (i < terms) result.termArray[result.terms++] = termArray[i++];
    while (j < poly.terms) result.termArray[result.terms++] = poly.termArray[j++];
    return result;
}
