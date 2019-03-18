package xyz.zinglix.mps;

import java.util.concurrent.atomic.AtomicLong;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

class test{
    public test(int count){
        this.count=count;
    }

    public int getCount(){
        return count;
    }

    private int count;
}

@RestController
public class GreetingController {
    private static final String template = "Hello, %s!";
    private final AtomicLong counter = new AtomicLong();

    @RequestMapping("/greeting")
    public test greeting(@RequestParam(value="name", defaultValue="World") String name) {
        return new test(3);
    }
}
