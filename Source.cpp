class Polynomial {
public:
    Polynomial(int capacity = 10); // �غc��
    ~Polynomial();                 // �Ѻc��

    Polynomial Add(const Polynomial& poly) const; // �[�k
    Polynomial Mult(const Polynomial& poly) const; // ���k
    float Eval(float x) const;                     // �����h����

    friend ostream& operator<<(ostream& os, const Polynomial& poly); // ��X�B��l
    friend istream& operator>>(istream& is, Polynomial& poly);       // ��J�B��l

private:
    Term* termArray; // �D�s�����}�C
    int capacity;    // �}�C�e�q
    int terms;       // �D�s���ƶq
    void Expand();   // �ʺA�X�i�}�C
};

// �֤ߥ[�k���
Polynomial Polynomial::Add(const Polynomial& poly) const {
    Polynomial result(capacity + poly.capacity); // �w�d�Ŷ�
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
    // �X�ֳѾl��
    while (i < terms) result.termArray[result.terms++] = termArray[i++];
    while (j < poly.terms) result.termArray[result.terms++] = poly.termArray[j++];
    return result;
}
