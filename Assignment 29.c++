Type Casting and Conversion

1.Write a C++ program to convert Primitive type to Complex type.
Example -
int main()
{
Complex c1;
Int x=5;
c1=x;
return 0;
}
2. Write a C++ program to convert Complex type to Primitive type.
Example -
int main()
{
Complex c1;
c1.setData(3,4);
int x;
x=c1;
return 0;
}
3. Create a Product class and convert Product type to Item type using constructor
int main()
{
Item i1;
Product p1;
p1.setData(3,4);
i1=p1;
return 0;
}

4. Create Product class and convert Product type to Item type using casting operator
int main()
{
Item i1;
Product p1;

p1.setData(3,4);
i1=p1;
return 0;
}
5. Create two classes Invent1 and Invent2 and also add necessary constructors in it. Now add
functions to support Invent1 to float and Invent1 to Invent2 type.
Example -
int main()
{
Invent1 s1=(4,5);
Invent2 d1;
float tv;
tv=s1;
d1=s1;
return 0;
}

6. Create a Time class and take Duration in seconds. Now you need to convert seconds(i.e in
int ) to Time class.

Example-
int main()

{
int duration;
cout<<”Enter time duration in minutes”;
cin>>duration;
Time t1 = duration;
t1.display();
return 0;
}
7. Create two class Time and Minute and add required getter and setter including constructors.
Now you need to type cast Time object into Minute to fetch the minute from Time and display it.
Example -
int main()
{
Time t1(2,30);
t1.display();
Minute m1;
m1.display();
m1=t1 // Fetch minute from time
t1.display();
m1.display();
return 0;
}

8. Create a Rupee class and convert it into int. And Display it.

Example-
int main()

{
Rupee r = 10;
int x = r;
cout<<x;
return 0;
}

9. Create a Dollar class and add necessary functions to support int to Dollar type conversion.

Example-
int main()

{
int x = 50;
Dollar d;
d = x;
d.display();
return 0;
}
10. Create two classes Rupee and Dollar and add necessary functions to support Rupee to
Dollar and Dollar to Rupee conversion.

Example-
int main()

{
Rupee r = 23;
Dollar d = r; // Rupee to Dollar conversion
d.display();
r.display();
r = d; // Dollar to Rupee Conversion
d.display();
r.display();
return 0;
}

Solution:-

1. #include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex() : real(0), imag(0) {}

    // Conversion constructor
    Complex(int r) : real(r), imag(0) {}

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1;
    int x = 5;
    c1 = x; // Implicit conversion using constructor
    c1.display();
    return 0;
}

2. #include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex() : real(0), imag(0) {}
    Complex(int r, int i) : real(r), imag(i) {}

    void setData(int r, int i) {
        real = r;
        imag = i;
    }

    // Conversion operator
    operator int() const {
        return real; // or you can return imag if needed
    }
};

int main() {
    Complex c1;
    c1.setData(3, 4);
    int x = c1; // Implicit conversion using operator
    cout << "Converted value: " << x << endl;
    return 0;
}

3. #include <iostream>
using namespace std;

class Item {
private:
    int a, b;
public:
    Item() : a(0), b(0) {}
    Item(int a, int b) : a(a), b(b) {}
    
    void display() const {
        cout << "Item - a: " << a << ", b: " << b << endl;
    }
};

class Product {
private:
    int x, y;
public:
    Product() : x(0), y(0) {}
    void setData(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // Conversion constructor
    operator Item() const {
        return Item(x, y);
    }
};

int main() {
    Item i1;
    Product p1;
    p1.setData(3, 4);
    i1 = p1; // Conversion using constructor
    i1.display();
    return 0;
}

4. #include <iostream>
using namespace std;

class Item {
private:
    int a, b;
public:
    Item() : a(0), b(0) {}
    Item(int a, int b) : a(a), b(b) {}
    
    void display() const {
        cout << "Item - a: " << a << ", b: " << b << endl;
    }
};

class Product {
private:
    int x, y;
public:
    Product() : x(0), y(0) {}
    void setData(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // Conversion operator
    explicit operator Item() const {
        return Item(x, y);
    }
};

int main() {
    Item i1;
    Product p1;
    p1.setData(3, 4);
    i1 = static_cast<Item>(p1); // Conversion using casting operator
    i1.display();
    return 0;
}

5. #include <iostream>
using namespace std;

class Invent2;

class Invent1 {
private:
    int x, y;
public:
    Invent1(int x = 0, int y = 0) : x(x), y(y) {}

    // Conversion to float
    operator float() const {
        return static_cast<float>(x + y);
    }

    // Conversion to Invent2
    operator Invent2() const;
};

class Invent2 {
private:
    int x;
public:
    Invent2() : x(0) {}

    // Conversion constructor
    Invent2(const Invent1 &i) : x(i.x + i.y) {}
};

int main() {
    Invent1 s1(4, 5);
    Invent2 d1;
    float tv = s1;
    d1 = s1; // Conversion using constructor

    cout << "Converted float value: " << tv << endl;
    return 0;
}
// Include Invent2 definition
Invent2 Invent1::operator Invent2() const {
    return Invent2(*this);
}


6. #include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int sec) : hours(sec / 3600), minutes((sec % 3600) / 60), seconds(sec % 60) {}

    void display() const {
        cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
    }
};

int main() {
    int duration;
    cout << "Enter time duration in seconds: ";
    cin >> duration;
    Time t1 = duration; // Conversion constructor
    t1.display();
    return 0;
}

7. #include <iostream>
using namespace std;

class Minute;

class Time {
private:
    int hours, minutes;
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void display() const {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }

    // Conversion operator to Minute
    operator Minute() const;
};

class Minute {
private:
    int minutes;
public:
    Minute() : minutes(0) {}

    // Display function
    void display() const {
        cout << minutes << " minutes" << endl;
    }

    // Conversion constructor
    Minute(const Time &t) : minutes(t.hours * 60 + t.minutes) {}
};

Time::operator Minute() const {
    return Minute(*this);
}

int main() {
    Time t1(2, 30);
    t1.display();
    Minute m1 = t1; // Conversion to Minute
    m1.display();
    return 0;
}

8. #include <iostream>
using namespace std;

class Rupee {
private:
    int amount;
public:
    Rupee(int amt = 0) : amount(amt) {}

    // Conversion operator to int
    operator int() const {
        return amount;
    }
};

int main() {
    Rupee r(10);
    int x = r; // Conversion to int
    cout << "Amount in integer: " << x << endl;
    return 0;
}

9. #include <iostream>
using namespace std;

class Dollar {
private:
    int amount;
public:
    Dollar(int amt = 0) : amount(amt) {}

    // Conversion constructor
    Dollar(int x) : amount(x) {}

    void display() const {
        cout << "Amount in dollars: " << amount << endl;
    }
};

int main() {
    int x = 50;
    Dollar d = x; // Conversion from int
    d.display();
    return 0;
}

10. #include <iostream>
using namespace std;

class Dollar;

class Rupee {
private:
    int amount;
public:
    Rupee(int amt = 0) : amount(amt) {}

    // Conversion operator to Dollar
    operator Dollar() const;

    void display() const {
        cout << "Amount in rupees: " << amount << endl;
    }
};

class Dollar {
private:
    int amount;
public:
    Dollar(int amt = 0) : amount(amt) {}

    // Conversion constructor
    Dollar(const Rupee &r) : amount(r.amount / 75) {} // Assuming 1 Dollar = 75 Rupees

    // Conversion operator to Rupee
    operator Rupee() const {
        return Rupee(amount * 75); // Assuming 1 Dollar = 75 Rupees
    }

    void display() const {
        cout << "Amount in dollars: " << amount << endl;
    }
};

Rupee::operator Dollar() const {
    return Dollar(*this);
}

int main() {
    Rupee r(2300);
    Dollar d = r; // Rupee to Dollar conversion
    d.display();
    r.display();
    r = d; // Dollar to Rupee conversion
    r.display();
    d.display();
    return 0;
}
