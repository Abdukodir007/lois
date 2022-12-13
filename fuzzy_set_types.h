// Лабораторная работа 2 по дисциплине ЛОИС
// Выполнена студентами группы 921731 БГУИР
// Болтаев М.М, Исматуллаев С.О, Муминов С.А, Хамидуллаев А.С, Тахиров С.Р
// Отдельная благодарность за предоставление кода Тарамин Д.В
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using RelationMatrix = std::vector<std::vector<double>>;
using Range = std::pair<double, double>;
using Solution = std::vector<Range>;
using Solutions = std::vector<Solution>;

class Name {
public:
  Name() = default;

  explicit Name(const std::string &str);

  std::string toString() const;

  bool operator==(const Name &rhs) const;

  bool operator!=(const Name &rhs) const;

  bool operator<(const Name &rhs) const;

private:
  char ch = -1;
  int32_t num = -1;
};

class SetName : public Name {
public:
  SetName() = default;

  explicit SetName(const std::string &str);
};

class RelationName : public Name {
public:
  RelationName() = default;

  explicit RelationName(const std::string &str);
};

class SetElemName : public Name {
public:
  SetElemName() = default;

  explicit SetElemName(const std::string &str);
};

class FuzzySetElem {
public:
  FuzzySetElem() = default;

  explicit FuzzySetElem(const SetElemName &inVar, double inVal);

  explicit FuzzySetElem(std::string str);

  SetElemName getVar() const;

  double getVal() const;

  std::string toString() const;

  bool operator<(const FuzzySetElem &el) const;

private:
  SetElemName var;
  double val{};
};

class FuzzySet : public std::vector<FuzzySetElem> {
public:
  FuzzySet() = default;

  explicit FuzzySet(std::string str);

  std::string toString() const;

  const SetName &getName() const;

private:
  SetName name;
};

class Relation {
public:
  Relation() = default;

  explicit Relation(const std::string &inStr);

  const RelationMatrix &getMatrix() const;

  const RelationName &getName() const;

private:
  RelationMatrix matrix;
  RelationName name;
};

class ReverseConclusion {
public:
  ReverseConclusion() = default;

  explicit ReverseConclusion(std::string str);

  std::string toString() const;

  void setSolutions(Solutions inSols);

  const SetName &getXSetName() const;

  const SetName &getYSetName() const;

  const RelationName &getRelationName() const;

private:
  static std::string doubleToString(double val);

  Solutions sols;
  SetName xSetName;
  SetName ySetName;
  RelationName relName;
};
