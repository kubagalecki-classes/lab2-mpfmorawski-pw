#pragma once

#include "Resource.hpp"

class ResourceManager
{

public:

  ResourceManager()
  {
    //std::cout << "Konstruktor domyslny.\n";
    resource = new Resource;
  }

  ResourceManager(const ResourceManager& RM)
  {
    //std::cout << "Konstruktor kopiujacy.\n";
    resource = new Resource{*RM.resource};
  }

  ResourceManager& operator=(const ResourceManager& RM)
  {
    //std::cout << "Kopiujacy operator przypisania.\n";
    if(this != &RM)
    {
      delete resource;
      resource = new Resource{*RM.resource};
    }
    return *this;
  }

  ResourceManager(ResourceManager&& RM)
  {
    //std::cout << "Konstruktor przenoszacy\n";
    resource = RM.resource;
    RM.resource = nullptr;
  }

  ResourceManager& operator=(ResourceManager&& RM)
  {
    //std::cout << "Przenoszacy operator przypisania.\n";
    if(this != &RM)
    {
      delete resource;
      resource = RM.resource;
      RM.resource = nullptr;
    }
    return *this;
  }

  double get()
  {
    return resource->get();
  }

  ~ResourceManager()
  {
    // std::cout << "Destruktor.\n";
    delete resource;
  }

private:
  Resource *resource = nullptr;
};