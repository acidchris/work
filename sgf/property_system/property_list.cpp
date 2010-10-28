#include "property_list.h"

namespace sgf
{

PropertyList::PropertyList()
{

}

PropertyList::PropertyList(std::map<Ogre::String, Ogre::StringVector>& property_list)
{
  this->swap(property_list);
}

PropertyList PropertyList::create(const Ogre::String& key, const Ogre::String& values, Ogre::String& delimiter /* = Ogre::String */)
{
  PropertyList newList;

  newList.addProperty(key, values, delimiter);

  return newList;
}

const Ogre::String& PropertyList::getValue(const Ogre::String& key, int index, const Ogre::String& defaultVal)
{
  PropertyList::iterator iter = find(key);

  if (iter != end())
  {
    Ogre::StringVector values = iter->second;

    if (index < static_cast<int>(values.size()))
    {
      return values.at(index);
    }
  }

  return defaultVal;
}

PropertyList& PropertyList::addProperty(const Ogre::String& key, const Ogre::String& values, Ogre::String& delimiter /* = Ogre::String */)
{
  Ogre::StringVector result;
  int num_splits = 0;
  size_t start, pos;

  start = 0;
  do
  {
    pos = values.find_first_of(delimiter, start);
    if (pos == start)
    {
      start = pos + 1; //do nothing
    }
    else if (pos == Ogre::String::npos)
    {
      result.push_back(values.substr(start)); //just copy the rest and advance
      break;
    }
    else
    {
      result.push_back(values.substr(start, pos - start)); //copy up to next delimiter
      start = pos + 1;
    }

    start = values.find_first_not_of(delimiter, start); //parse up to next real data
    ++num_splits;
  } while (pos != Ogre::String::npos);

  //insert into list
  insert(PropertyPair(key, result));
  return *this;
}

} //sgf
