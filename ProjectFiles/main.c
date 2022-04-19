#include<FreeRTOS.h>
#include<task.h>
#include<stdio.h>
#include"pico/stdlib.h"

void led_task(){
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(1){
        gpio_put(LED_PIN,1);
        vTaskDelay(100);
        gpio_put(LED_PIN,0);
        vTaskDelay(100);
    }
}

int main(){

    stdio_init_all(); //Main initialization


    xTaskCreate(led_task,"LED_Task",256,NULL,1, NULL); 
    //Setup the task, arguments(TASK_NAME, TASK_DESCIPTION, NUMBER OF WORDS TO ALLOCATES TASK STACK, NUMBER OF ARGUMENTS IN TASK FUCTION, TASK PRIORITY, LAST ARGUMENT OF THE FUNCTION) 
      
    vTaskStartScheduler(); 
    //This function is starting tasking in system

    while(1){};
    //Main infinite loop for program, actually not using because we are only using infinity int task
}
