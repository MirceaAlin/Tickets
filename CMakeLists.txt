cmake_minimum_required(VERSION 3.27)
project(Laborator9_10)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laborator9_10 main.cpp
        Repo.h
        Bilet.cpp
        Tranzactie.cpp
        Entities.h
        Repo_tranzacti.cpp
        Repo_Bilet.cpp
        Service.h
        Service.cpp
        Ui.h
        Ui.cpp
        teste.h
        teste.cpp
        RepoFileBilet.h
        RepoFileBilet.cpp
        RepoFileBani.cpp
        Validator.h
        Exceptii_Entitate.h
        Exceptii_Repo.h
        Exceptii_Service.h)
