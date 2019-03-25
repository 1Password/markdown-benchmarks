use std::fs;
use std::time::Instant;
use pulldown_cmark::{Parser, Options, html};

fn main() {
    let input = fs::read_to_string("../sample1.md")
        .expect("failed to read file");

    {
        let iterations = 1000;
        let now = Instant::now();
        for _i in 0..iterations {
            let parser = Parser::new_ext(&input, Options::empty());
            let mut html_output: String = String::with_capacity(input.len() * 3 / 2);
            html::push_html(&mut html_output, parser);
        }
        println!("{:6} iterations = {:3}.{:03}s", iterations, now.elapsed().as_secs(), now.elapsed().subsec_millis());
    }

    {
        let iterations = 10_000;
        let now = Instant::now();
        for _i in 0..iterations {
            let parser = Parser::new_ext(&input, Options::empty());
            let mut html_output: String = String::with_capacity(input.len() * 3 / 2);
            html::push_html(&mut html_output, parser);
        }
        println!("{:6} iterations = {:3}.{:03}s", iterations, now.elapsed().as_secs(), now.elapsed().subsec_millis());
    }

    {
        let iterations = 100_000;
        let now = Instant::now();
        for _i in 0..iterations {
            let parser = Parser::new_ext(&input, Options::empty());
            let mut html_output: String = String::with_capacity(input.len() * 3 / 2);
            html::push_html(&mut html_output, parser);
        }
        println!("{:6} iterations = {:3}.{:03}s", iterations, now.elapsed().as_secs(), now.elapsed().subsec_millis());
    }
}
