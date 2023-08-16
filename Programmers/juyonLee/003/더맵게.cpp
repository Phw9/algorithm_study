#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //데이터 자동정렬되어서 우선순위큐 사용.
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    while(pq.size()>1 && pq.top() < K)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first+(second*2));
        answer+=1;
    }
    
    //모든 음식 스코빌 지수 k이상일 때가 없음.
    if(pq.top()<K)
        return -1;
    
    return answer;
}


using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gameManager : MonoBehaviour
{
    public Text timeTxt;
    float time;
    public GameObject card;
    public GameObject retryBtn;

    // Start is called before the first frame update
    void Start()
    {
        for (int i =0; i<16; i++)  
        {
            GameObject newCard = Instantiate(card);
            newCard.transform.parent = GameObject.Find("cards").transform;

            float x = (i / 4) * 1.4f - 2.1f;
            float y = (i % 4) * 1.4f - 3.0f;
            newCard.transform.position = new Vector3(x, y, 0);
        }
    }

    // Update is called once per frame
    void Update()
    {
        /*
        time += Time.deltaTime;
        timeTxt.text = time.ToString("N2");
        */
        if(time < 2.0f)
        {
            time += Time.deltaTime;
            timeTxt.text = time.ToString("N2");

            //Time.timeScale = 0.0f;
            //retryBtn.SetActive(true);
        }

        else
        {
            retryBtn.SetActive(true);
        }
        /*
        if(retryBtn.activeSelf == false)
        {
            Time.timeScale = 1.0f;
        }
        */
    }
}

