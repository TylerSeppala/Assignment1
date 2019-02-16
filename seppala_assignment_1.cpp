//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 1

//This code takes user input to locate a file that contains DNA strings.
//Basic statistics are calculated from these strings and then used to print
//1000 new DNA strings to an output file.

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Operations
{
public:
  double a_counter = 0;
  double t_counter = 0;
  double c_counter = 0;
  double g_counter = 0;
  double aa_counter = 0;
  double at_counter = 0;
  double ac_counter = 0;
  double ag_counter = 0;
  double ta_counter = 0;
  double tt_counter = 0;
  double tc_counter = 0;
  double tg_counter = 0;
  double ca_counter = 0;
  double ct_counter = 0;
  double cc_counter = 0;
  double cg_counter = 0;
  double ga_counter = 0;
  double gt_counter = 0;
  double gc_counter = 0;
  double gg_counter = 0;
  double a_probability = 0;
  double t_probability = 0;
  double c_probability = 0;
  double g_probability = 0;
  double aa_probability = 0;
  double at_probability = 0;
  double ac_probability = 0;
  double ag_probability = 0;
  double ta_probability = 0;
  double tt_probability = 0;
  double tc_probability = 0;
  double tg_probability = 0;
  double ca_probability = 0;
  double ct_probability = 0;
  double cc_probability = 0;
  double cg_probability = 0;
  double ga_probability = 0;
  double gt_probability = 0;
  double gc_probability = 0;
  double gg_probability = 0;
  void reset_vars()
  {
    a_counter = 0;
    t_counter = 0;
    c_counter = 0;
    g_counter = 0;
    aa_counter = 0;
    at_counter = 0;
    ac_counter = 0;
    ag_counter = 0;
    ta_counter = 0;
    tt_counter = 0;
    tc_counter = 0;
    tg_counter = 0;
    ca_counter = 0;
    ct_counter = 0;
    cc_counter = 0;
    cg_counter = 0;
    ga_counter = 0;
    gt_counter = 0;
    gc_counter = 0;
    gg_counter = 0;
    a_probability = 0;
    t_probability = 0;
    c_probability = 0;
    g_probability = 0;
    aa_probability = 0;
    at_probability = 0;
    ac_probability = 0;
    ag_probability = 0;
    ta_probability = 0;
    tt_probability = 0;
    tc_probability = 0;
    tg_probability = 0;
    ca_probability = 0;
    ct_probability = 0;
    cc_probability = 0;
    cg_probability = 0;
    ga_probability = 0;
    gt_probability = 0;
    gc_probability = 0;
    gg_probability = 0;
  }
  double sum(string dna)
  {
    double sum = 0;
    for (int i = 0; i < dna.length() - 1; i++)
    {
      sum += 1;
    }
    return sum;
  }
  void count_letters(string dna)
  {
    char last_char;
    string bigram;
    for (char x : dna)
    {
      switch (x)
      {
        case 'A': a_counter++;
            break;
        case 'a': a_counter++;
            break;
        case 'T': t_counter++;
            break;
        case 't': t_counter++;
            break;
        case 'C': c_counter++;
            break;
        case 'c': c_counter++;
            break;
        case 'G': g_counter++;
            break;
        case 'g': g_counter++;
            break;
      }
      last_char = tolower(last_char);
      x = tolower(x);
      bigram = "";
      bigram = bigram + last_char + x;

      if (bigram == "aa")
      {
        aa_counter++;
      }
      if (bigram == "at")
      {
        at_counter++;
      }
      if (bigram == "ac")
      {
        ac_counter++;
      }
      if (bigram == "ag")
      {
        ag_counter++;
      }
      if (bigram == "ta")
      {
        ta_counter++;
      }
      if (bigram == "tt")
      {
        tt_counter++;
      }
      if (bigram == "tc")
      {
        tc_counter++;
      }
      if (bigram == "tg")
      {
        tg_counter++;
      }
      if (bigram == "ca")
      {
        ca_counter++;
      }
      if (bigram == "ct")
      {
        ct_counter++;
      }
      if (bigram == "cc")
      {
        cc_counter++;
      }
      if (bigram == "cg")
      {
        cg_counter++;
      }
      if (bigram == "ga")
      {
        ga_counter++;
      }
      if (bigram == "gt")
      {
        gt_counter++;
      }
      if (bigram == "gc")
      {
        gc_counter++;
      }
      if (bigram == "gg")
      {
        gg_counter++;
      }

      last_char = x;
    }
  }
  void probability(double total_sum, double counter)
  {
    double sum = (double)total_sum;
    double count = (double)counter;
    a_probability = a_counter / sum;
    t_probability = t_counter / sum;
    c_probability = c_counter / sum;
    g_probability = g_counter / sum;
    aa_probability = aa_counter / (sum - count);
    at_probability = at_counter / (sum - count);
    ac_probability = ac_counter / (sum - count);
    ag_probability = ag_counter / (sum - count);
    ta_probability = ta_counter / (sum - count);
    tt_probability = tt_counter / (sum - count);
    tc_probability = tc_counter / (sum - count);
    tg_probability = tg_counter / (sum - count);
    ca_probability = ca_counter / (sum - count);
    ct_probability = ct_counter / (sum - count);
    cc_probability = cc_counter / (sum - count);
    cg_probability = cg_counter / (sum - count);
    ga_probability = ga_counter / (sum - count);
    gt_probability = gt_counter / (sum - count);
    gc_probability = gc_counter / (sum - count);
    gg_probability = gg_counter / (sum - count);
  }
  string generate(double standard_dev, double mean)
  {
    string line;
    double a = ((double) rand() / (RAND_MAX));
    double b = ((double) rand() / (RAND_MAX));
    double rando;
    double c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
    int d = (int)(standard_dev * c + mean);
    for (int i = 0; i < d; i++)
    {
      rando = ((double) rand() / (RAND_MAX));
      if (rando < a_probability)
      {
        line += "a";
      }
      else if (rando < (a_probability + t_probability))
      {
        line += "t";
      }
      else if (rando < (a_probability + t_probability + c_probability))
      {
        line += "c";
      }
      else
      {
        line += "g";
      }
    }
    return line;
  }
};

int main()
{
  Operations op;
  bool appending = false;
  string filename;
  while (true)
  {
    cout << "Please enter the name of a file which contains DNA strings: ";
    cin >> filename;

    string line;
    double counter = 0;
    double total_sum = 0;
    double var_sum = 0;
    double variance = 0;
    double mean = 0;
    double standard_dev = 0;
    op.reset_vars();

    ifstream read_file (filename);
    if (read_file.is_open())
    {
      while ( getline (read_file,line) )
      {
        counter += 1;
        total_sum += op.sum(line);
        op.count_letters(line);
      }
      mean = total_sum / counter;
      read_file.clear();
      read_file.seekg(0, ios::beg);

      while ( getline (read_file,line) )
      {
        var_sum += pow((op.sum(line) - mean), 2);
      }
      variance = var_sum / counter;
      standard_dev = sqrt(variance);
      op.probability(total_sum, counter);
      read_file.close();
    }

    else cout << "Unable to open file" << endl;

    ofstream write_file;
    if (!appending)
    {
      write_file.open ("TylerSeppala.out");
      write_file << "Tyler Seppala\n2297817\nseppala@chapman.edu\nCPSC 350-02\nAssignment 1\n" << endl;
      write_file.close();
    }
    write_file.open("TylerSeppala.out", std::ios_base::app);
    write_file << endl;
    write_file << filename << endl;
    write_file << "-------------------------" << endl;
    write_file << "Total Sum: " << total_sum << endl;
    write_file << "Mean: " << mean << endl;
    write_file << "Variance: " << variance << endl;
    write_file << "Standard Deviation: " << standard_dev << endl;
    write_file << "Probability: " << endl;
    write_file << "\tA: " << op.a_probability << endl;
    write_file << "\tT: " << op.t_probability << endl;
    write_file << "\tC: " << op.c_probability << endl;
    write_file << "\tG: " << op.g_probability << endl;
    write_file << "\tAA: " << op.aa_probability << endl;
    write_file << "\tAT: " << op.at_probability << endl;
    write_file << "\tAC: " << op.ac_probability << endl;
    write_file << "\tAG: " << op.ag_probability << endl;
    write_file << "\tTA: " << op.ta_probability << endl;
    write_file << "\tTT: " << op.tt_probability << endl;
    write_file << "\tTC: " << op.tc_probability << endl;
    write_file << "\tTG: " << op.tg_probability << endl;
    write_file << "\tCA: " << op.ca_probability << endl;
    write_file << "\tCT: " << op.ct_probability << endl;
    write_file << "\tCC: " << op.cc_probability << endl;
    write_file << "\tCG: " << op.cg_probability << endl;
    write_file << "\tGA: " << op.ga_probability << endl;
    write_file << "\tGT: " << op.gt_probability << endl;
    write_file << "\tGC: " << op.gc_probability << endl;
    write_file << "\tGG: " << op.gg_probability << endl;
    for (int i = 0; i <= 1000; i++)
    {
      write_file << op.generate(standard_dev, mean) << endl;
    }

    string continuing;
    cout << "Done." << endl;
    cout << endl;
    cout << "Would you like to process another DNA list? (y/n)" << endl;
    cin >> continuing;

    if (continuing == "n")
    {
      break;
    }
    else
    {
      appending = true;
    }
  }
  return 0;
}
