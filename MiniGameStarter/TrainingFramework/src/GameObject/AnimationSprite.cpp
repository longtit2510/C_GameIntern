#include "AnimationSprite.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"

AnimationSprite::AnimationSprite() : m_numFrames(0),m_currentFrame(0),m_frameTime(0.0f), m_currentframeTime(0.0f)
{}
AnimationSprite::AnimationSprite(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int numFrames, float frameTime) : Sprite2D(model,shader,texture), m_numFrames(numFrames), m_currentFrame(0), m_frameTime(frameTime), m_currentframeTime(0.0f) {

}
void AnimationSprite::Init()
{
	velo.x = 0.0f;
	velo.y = 0.0f;
	original.x = this->GetPosition().x;
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void AnimationSprite::Draw()
{
	if (m_pCamera == nullptr) return;
	glUseProgram(m_pShader->m_program);
	glBindBuffer(GL_ARRAY_BUFFER, m_pModel->GetVertexObject());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pModel->GetIndiceObject());

	GLuint iTempShaderVaribleGLID = -1;
	Matrix wvpMatrix;

	wvpMatrix = m_worldMatrix * m_pCamera->GetLookAtCameraMatrix();

	if (m_pTexture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_pTexture->Get2DTextureAdd());
		if (m_pShader->m_iTextureLoc[0] != -1)
			glUniform1i(m_pShader->m_iTextureLoc[0], 0);
	}
	else
	{
		iTempShaderVaribleGLID = -1;
		iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_color");
		if (iTempShaderVaribleGLID != -1)
			glUniform4f(iTempShaderVaribleGLID, m_color.x, m_color.y, m_color.z, m_color.w);
	}


	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_posL");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_POSITION);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_uv");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_UV);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_alpha");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, 1.0);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_wvpMatrix");
	if (iTempShaderVaribleGLID != -1)
		glUniformMatrix4fv(iTempShaderVaribleGLID, 1, GL_FALSE, wvpMatrix.m[0]);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_numFrames");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, m_numFrames);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_currentFrame");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, m_currentFrame);



	glDrawElements(GL_TRIANGLES, m_pModel->GetNumIndiceObject(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void AnimationSprite::Update(GLfloat deltatime)
{
	//Animation
	m_currentframeTime += deltatime;
	if (m_currentframeTime >= m_frameTime) {
		m_currentFrame++;
		if (m_currentFrame >= m_numFrames) {
			m_currentFrame = 0;
		}
		m_currentframeTime -= m_frameTime;
	}

}
void AnimationSprite::UpdateFlip(GLfloat deltatime)
{
	//Animation
	m_currentFrame = m_numFrames;
	m_currentframeTime += deltatime;
	if (m_currentframeTime >= m_frameTime) {
		m_currentFrame--;
		if (m_currentFrame <= 0) {
			m_currentFrame = m_numFrames;
		}
		m_currentframeTime -= m_frameTime;
	}

}
void AnimationSprite::UpdateEnemy(GLfloat deltaTime) {
	
}

void AnimationSprite::move(GLfloat vx, GLfloat vy,GLfloat deltaTime) {
	velo.x = vx * (m_movementspeed) * deltaTime;
	this->m_position.x += (velo.x);
	
}

void AnimationSprite::enemyPatrol(GLfloat deltaTime) {
	velo.x = 1.0f * (m_movementspeed)*deltaTime;
	if (s <= 10.0f) {
		this->m_position.x += velo.x;
	}
	if (50.0f >= s >= 10.0f) {
		this->m_position.x -= velo.x;
	}
	if (s >= 50.0f) {
		s = 0.0f;
	}
}


void AnimationSprite::jump(GLfloat deltaTime, GLfloat gravity, GLfloat jumpHeight) {
	velo.y = -(2.0f * gravity * jumpHeight * deltaTime);
	this->m_position.y += velo.y;
}

void AnimationSprite::updatePhysics(GLfloat gravity, GLfloat deltaTime) {
	velo.y = 1.0f * gravity * deltaTime;
	this->m_position.y += velo.y;
	CalculateWorldMatrix();
}



