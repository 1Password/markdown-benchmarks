use std::fs;
use std::time::Instant;
use comrak::{markdown_to_html, ComrakOptions};

fn main() {
    let input = fs::read_to_string("../sample1.md")
        .expect("failed to read file");

    {
        let iterations = 1000;
        let now = Instant::now();
        for _i in 0..iterations {
            let _output = markdown_to_html(&input, &ComrakOptions::default());
        }
        println!("{:6} iterations = {:3}.{:03}s", iterations, now.elapsed().as_secs(), now.elapsed().subsec_millis());
    }

    {
        let iterations = 10_000;
        let now = Instant::now();
        for _i in 0..iterations {
            let _output = markdown_to_html(&input, &ComrakOptions::default());
        }
        println!("{:6} iterations = {:3}.{:03}s", iterations, now.elapsed().as_secs(), now.elapsed().subsec_millis());
    }

    {
        let iterations = 100_000;
        let now = Instant::now();
        for _i in 0..iterations {
            let _output = markdown_to_html(&input, &ComrakOptions::default());
        }
        println!("{:6} iterations = {:3}.{:03}s", iterations, now.elapsed().as_secs(), now.elapsed().subsec_millis());
    }
}
