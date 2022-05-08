#pragma once

#ifndef SINGLETON_CPP
#define SINGLETON_CPP

template <class T>

class Singleton{
public:
  static inline T* get(){
    if(m_pSingleton == nullptr){
      m_pSingleton = new T;
    }

    return m_pSingleton;
  }

  static void remove(){
    if(m_pSingleton != nullptr){
      delete(m_pSingleton);

      m_pSingleton = nullptr;
    }
  }

  static bool exists(){
    return (m_pSingleton != nullptr);
  }

protected:
  static T* m_pSingleton;
};

template <class T>
T* Singleton<T>::m_pSingleton = nullptr;

#endif
