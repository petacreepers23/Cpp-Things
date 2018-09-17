#include <Windows.h>
#include <tchar.h>
#include <iostream>

namespace {
      
      /*
				No throw
				Funcion que envia datos situados en szMsg a un filemap hMapfile con un tamaño size
			*/
			int sendFileMap(HANDLE hMapFile, char* szMsg, SIZE_T size) {
				if (szMsg == NULL) { return 3; }
				LPCTSTR pBuf;
				pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, size);
				if (pBuf == NULL) { _tprintf(TEXT("Could not map view of file (%d).\n"), GetLastError()); CloseHandle(hMapFile); return 1; }
				CopyMemory((PVOID)pBuf, szMsg, size);
				if (!FlushViewOfFile(pBuf, 0)) {
					std::printf("Flush FileMap error: %d.\n", GetLastError());
					UnmapViewOfFile(pBuf);
					return 2;
				}
				UnmapViewOfFile(pBuf);
				return 0;
			}
			/*
				No throw
				Funcion que recibe datos 
			*/
			int reciveFileMap(HANDLE hMapFile, char* szMsg, SIZE_T size) {
				if (szMsg == NULL) { return 3; }
				LPCTSTR pBuf;
				pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, size);
				if (pBuf == NULL) { _tprintf(TEXT("Could not map view of file (%d).\n"), GetLastError()); CloseHandle(hMapFile); return 1; }
				CopyMemory(szMsg, (PVOID)pBuf, size);
				UnmapViewOfFile(pBuf);
				return 0;
			}

			/*
				No throw, null if failed
				Funcion que crea un mapfile, null si falla. se debe enviar la ruta
			*/
			HANDLE createMapFile(const char name[256], SIZE_T size) {
				HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, size, name);
				
				if (hMapFile == NULL) {
					std::printf("Error creating FileMap, error code: %d\n.", GetLastError());
					return NULL;
				}
				return hMapFile;
			}
 }
