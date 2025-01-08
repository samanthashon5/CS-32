//Your declarations and implementations would go here
class Investment
{
public:
  Investment(string name, int price)
  {
    name_ = name;
    price_ = price;
  }

  virtual ~Investment(){};

  string name() const
  {
    return name_;
  }

  int purchasePrice() const
  {
    return price_;
  }
  //pure virtual
  virtual string description() const = 0;

  //stocks are fungible but houses and paintings are not
  virtual bool fungible() const = 0;

  private:
    string name_;
    int price_;
};

class Painting: public Investment
{
public:
  Painting(string name, int price):Investment(name, price)
  {}

  virtual ~Painting()
  {
    cout << "Destroying " << name() << ", a painting" << endl;
  }

  virtual string description() const
  {
    return "painting";
  }

  virtual bool fungible() const
  {
    return false;
  }

};

class Stock: public Investment
{
public:
  Stock(string name, int price, string nick): Investment(name, price), tsymbol(nick)
  {}

  virtual ~Stock()
  {
    cout << "Destroying " << name() << ", a stock holding" << endl;
  }

  virtual string description() const
  {
    return "stock trading as " + tsymbol;
  }

  virtual bool fungible() const
  {
    return true;
  }

  private:
  string tsymbol;
};

class House: public Investment
{
public:
  House(string name, int price): Investment(name, price)
  {}

  virtual ~House()
  {
    cout << "Destroying the house " << name() << endl;
  }

  virtual string description() const
  {
    return "house";
  }
  
  virtual bool fungible() const
  {
    return false;
  }
};
