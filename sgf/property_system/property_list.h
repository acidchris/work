#ifndef _PROPERTY_LIST_H_
#define _PROPERTY_LIST_H_

#include <OgreString.h>
#include <OgreStringVector.h>

namespace sgf
{
  typedef std::pair<Ogre::String, Ogre::StringVector>   PropertyPair;

  class PropertyList : public std::map<Ogre::String, Ogre::StringVector>
  {
  public:
    PropertyList();
    PropertyList(std::map<Ogre::String, Ogre::StringVector>& property_list);
    virtual ~PropertyList() { }

    static PropertyList create(const Ogre::String& key, const Ogre::String& values, Ogre::String& delimiter = Ogre::String(" "));

    const Ogre::String&  getValue(const Ogre::String& key, int index, const Ogre::String& defaultVal);

    PropertyList& addProperty(const Ogre::String& key, const Ogre::String& values, Ogre::String& delimiter = Ogre::String(" "));  //with support for chaining property values
    PropertyList& operator()(const Ogre::String& key, const Ogre::String& values, Ogre::String& delimiter = Ogre::String(" "))
    {
      return addProperty(key, values, delimiter);
    }
  };

} //sgf

#endif
