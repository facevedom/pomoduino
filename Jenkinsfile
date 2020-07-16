pipeline {
    agent any

    stages {
        stage('Compile') {
            steps {
                dir('Pomoduino') {
                    sh 'arduino-cli compile --fqbn arduino:avr:uno'
                }
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
