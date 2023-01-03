use std::fs::File;
use std::io::{LineWriter, Write};

struct Vec3 {
    value: [f32; 3],
}

impl Vec3 {
    pub fn new(v0: f32, v1: f32, v2: f32) -> Self {
        Vec3 {
            value: [v0, v1, v2],
        }
    }

    pub fn x(&self) -> f32 {
        self.value[0]
    }

    pub fn y(&self) -> f32 {
        self.value[1]
    }

    pub fn z(&self) -> f32 {
        self.value[2]
    }
}

fn main() -> std::io::Result<()> {
    let file = File::create("image.ppm")?;
    let mut file = LineWriter::new(file);
    let w = 256;
    let h = 256;
    file.write_fmt(format_args!("P3\n{} {}\n255\n", w, h))?;
    for i in 0..h {
        for j in 0..w {
            let v = Vec3::new(
                i as f32 / (w - 1) as f32 * 255.999,
                j as f32 / (h - 1) as f32 * 255.999,
                0.25 * 255.999,
            );
            file.write_fmt(format_args!(
                "{} {} {}\n",
                v.x() as i32,
                v.y() as i32,
                v.z() as i32
            ))?
        }
    }
    Ok(())
}
