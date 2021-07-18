/*
CS154 Lab 5
This contains code of a program illustrating the use of Inheritance
and Dynamic Binding.

I do so by designing a program denoting the Supply Chain with the classes
being FactoryProduce, WholeSalePackage and RetailProduct.

Author: Shubh Kumar
200050134

*/

#include <bits/stdc++.h>

using namespace std;


class FactoryProduce{

  double sp;          //Selling price to WholeSale
  double cp;          //Actual price of Production
  double profit;      //Profit made sp-cp


public:
  FactoryProduce (double _cp, double margin) {
    cp = _cp;
    sp = ( cp * ( margin / 100.0 ) ) + cp;
    profit = sp-cp;
  };
  void PrintFactoryProfit() {
      cout<<"Profit on Factory's end is: "<<profit<<endl;
  };

  virtual void PrintWholesaleProfit() = 0;
  virtual void PrintRetailProfit() = 0;
};

class WholeSalePackage: public FactoryProduce {

  double sp;          //Selling price to Retailer
  double cp;          //Price for which package was procured
  double profit;      //Profit made sp-cp

public:

  // The Expression in Line 47 is for CP for factory
  WholeSalePackage(double _cp, double WholeSaleMargin, double FactoryMargin):
  FactoryProduce( _cp / ( 1 + (FactoryMargin/100.0) ) ,FactoryMargin) {
    cp = _cp;
    sp = ( cp * ( WholeSaleMargin / 100.0 ) ) + cp;
    profit = sp-cp;

  };

  void PrintWholesaleProfit() {
      cout<<"Profit on Whole-Sale's end is: "<<profit<<endl;
  };


};

class RetailProduct: public WholeSalePackage {

  double sp;          //Selling price to Consumer
  double cp;          //Price for which package was sold
  double profit;      //Profit made sp-cp

public:
  // The Expression in Line 69 is for CP for WholeSaler
  RetailProduct(double _cp, double WholeSaleMargin, double FactoryMargin,
  double RetailMargin): WholeSalePackage(_cp / ( 1 + (WholeSaleMargin/100.0) ),
  WholeSaleMargin, FactoryMargin){

    cp = _cp;
    sp = ( cp * ( RetailMargin / 100.0 ) ) + cp;
    profit = sp-cp;

  }

  //No need of virtual as we will no longer inherit it further
  void PrintRetailProfit() {
      cout<<"Profit on Retailer's end is: "<<profit<<endl;
  };

};


int main(int argc, char* argv[]){

  FactoryProduce* FP;
  WholeSalePackage* WP;
  RetailProduct* RP;

  // Statically initiated variables
//  FactoryProduce Fp(100, 20);
//  WholeSalePackage Wp(200,15,10);
  RetailProduct Rp(300,20,15,10);

  // FP = new FactoryProduce(100, 20);
  // FP->PrintFactoryProfit();

//  WP = new WholeSalePackage(200,15,10);
//  WP->PrintWholesaleProfit();
//  WP->PrintFactoryProfit();

  RP = new RetailProduct(300,20,15,10);
  RP->PrintRetailProfit();
  RP->PrintWholesaleProfit();
  RP->PrintFactoryProfit();


}
