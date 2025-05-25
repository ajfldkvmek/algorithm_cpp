cpp 알고리즘 공부

vscode ide 에서 컴파일이 제대로 실행이 안되면 터미널에서 실행하자

-02
| 옵션 | 설명 |
| -------- | ------------------------------------ |
| `-O0` | 최적화 없음 (디버깅에 유리) |
| `-O1` | 기본적인 최적화 |
| `-O2` | 대부분의 최적화 적용 (추천) |
| `-O3` | 가능한 최고 수준 최적화 (하지만 코드 부풀고 예측 어렵기도 함) |
| `-Ofast` | `-O3` + 안전성 무시하고 더 공격적인 최적화 |
| `-Os` | 코드 크기 줄이기 최적화 (임베디드용) |

- Wall
  | 옵션 | 설명 |
  | ----------------- | -------------------------------------- |
  | `-Wall` | 일반적인 대부분의 경고를 활성화 |
  | `-Wextra` | `-Wall`로는 포함되지 않는 추가 경고까지 활성화 |
  | `-Wpedantic` | ISO 표준에 어긋나는 코드에 대해서도 경고 (엄격한 표준 준수) |
  | `-Wshadow` | 같은 이름의 지역 변수/전역 변수가 가려질 때 경고 |
  | `-Wconversion` | 형 변환 시 데이터 손실 가능성이 있으면 경고 |
  | `-Wformat` | `printf`/`scanf`와 실제 인자 타입이 안 맞을 경우 경고 |
  | `-Wfloat-equal` | 부동소수점 == 비교에 대해 경고 |
  | `-Wundef` | 정의되지 않은 매크로 사용 시 경고 |
  | `-Wsign-compare` | signed와 unsigned 타입 비교 시 경고 |
  | `-Wuninitialized` | 초기화되지 않은 변수 사용 시 경고 |
  | `-Werror` | 경고를 에러로 처리해서 컴파일 자체를 실패시킴 |

g++ -std=c++17 -Wall -O2 main.cpp -o main && ./main
g++ -std=c++14 originFilename -o outputFileName
ex: g++ -std=c++14 unique.cpp -o unique

| 목적               | 추천 옵션                                 |
| ------------------ | ----------------------------------------- |
| 실전 알고리즘      | `-Wall -Wextra -O2`                       |
| C++ 학습/디버깅    | `-Wall -Wextra -Wshadow -Wconversion -O0` |
| 엄격한 표준 검사   | `-Wall -Wextra -Wpedantic`                |
| 경고도 에러로 처리 | 추가로 `-Werror`                          |

추천

vscode 에서 터미널 열기:: ^ + shift + `

terminal / editor 이동 단축키: ^ + `
